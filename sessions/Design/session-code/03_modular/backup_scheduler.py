"""
Calsoft Engineering Internship 2026
Session: Software Design Principles and Engineering Workflow
Block: Design Before Code (10:00 - 10:45) — Step 3

MODULAR VERSION — The Good Design

Compare with 02_monolith/backup_scheduler.py.

This scheduler does ONE thing: schedule and execute backups.
It does not know how to log. It does not know how to send email.
It calls interfaces. The interfaces handle the rest.

WHAT CHANGED:
  - Logging is a separate module (logger.py)
  - Notifications are a separate module (notifications.py)
  - The scheduler depends on abstractions, not on email/Slack/SMS directly
  - Adding a new notification channel requires ZERO changes to this file

"""

import time
import random

from logger import BackupLogger
from notifications import (
    NotificationService,
    EmailNotifier,
    SlackNotifier,
    SmsNotifier,
)


class BackupScheduler:
    """
    Schedules and executes backup jobs.
    Delegates logging and notification to injected dependencies.
    """

    def __init__(self, logger, notification_service):
        self.jobs = []
        self.logger = logger
        self.notifications = notification_service

    def add_job(self, job_name, source_path, destination_path):
        self.jobs.append({
            "name": job_name,
            "source": source_path,
            "destination": destination_path,
            "status": "pending"
        })

    def run_all_jobs(self):
        for job in self.jobs:
            print(f"\n  Starting backup: {job['name']}")

            try:
                time.sleep(0.1)
                success = self._copy_data(job["source"], job["destination"])

                if success:
                    job["status"] = "completed"
                    self.logger.info(job["name"], f"Backup completed: {job['name']}")
                else:
                    raise Exception("Copy operation returned failure")

            except Exception as e:
                job["status"] = "failed"
                self.logger.error(job["name"], f"Backup FAILED: {job['name']} — {e}")
                self.notifications.notify_failure(
                    job["name"],
                    str(e),
                    {"source": job["source"], "destination": job["destination"]}
                )

    def _copy_data(self, source, destination):
        """Simulate a backup copy operation."""
        return random.random() > 0.2

    def print_summary(self):
        print("\n" + "=" * 50)
        print("  BACKUP SUMMARY")
        print("=" * 50)
        completed = sum(1 for j in self.jobs if j["status"] == "completed")
        failed = sum(1 for j in self.jobs if j["status"] == "failed")
        print(f"  Total jobs:    {len(self.jobs)}")
        print(f"  Completed:     {completed}")
        print(f"  Failed:        {failed}")
        for entry in self.logger.get_entries():
            level_tag = "OK" if entry["level"] == "INFO" else "FAIL"
            print(f"  [{level_tag}] {entry['message']}")
        print("=" * 50)


# ────────────────────────────────────────────────────
# Usage — notice how notification channels are configured
# outside the scheduler. The scheduler never knows about them.
# ────────────────────────────────────────────────────
if __name__ == "__main__":
    # Set up logging
    logger = BackupLogger()

    # Set up notifications — add or remove channels here
    # The scheduler code above does not change.
    notifications = NotificationService()
    notifications.register(EmailNotifier(
        smtp_server="smtp.calsoft.internal",
        sender="backup-system@calsoft.internal",
        recipient="storage-ops@calsoft.internal"
    ))
    notifications.register(SlackNotifier(
        webhook_url="https://hooks.slack.com/services/...",
        channel="storage-alerts"
    ))
    notifications.register(SmsNotifier(
        phone_number="+91-98765-43210"
    ))

    # Create and run scheduler
    scheduler = BackupScheduler(logger, notifications)
    scheduler.add_job("daily-db-backup", "/data/postgres", "/backup/postgres")
    scheduler.add_job("config-snapshot",  "/etc/configs",   "/backup/configs")
    scheduler.add_job("log-archive",      "/var/logs",      "/backup/logs")

    scheduler.run_all_jobs()
    scheduler.print_summary()
