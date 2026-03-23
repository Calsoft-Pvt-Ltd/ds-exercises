"""
Calsoft Engineering Internship 2026
Session: Software Design Principles and Engineering Workflow


MONOLITHIC VERSION — The Bad Design

This is a working backup scheduler. It schedules backups, runs them,
logs results, and sends email notifications on failure.

It works. The problem is what happens when requirements change.

"""

import time
import smtplib
from datetime import datetime


class BackupScheduler:
    """
    Handles everything: scheduling, execution, logging,
    and email notification. All in one class.
    """

    def __init__(self):
        self.backup_jobs = []
        self.log_entries = []
        self.smtp_server = "smtp.calsoft.internal"
        self.smtp_port = 587
        self.alert_email = "storage-ops@calsoft.internal"
        self.sender_email = "backup-system@calsoft.internal"

    def add_job(self, job_name, source_path, destination_path, schedule_hour):
        self.backup_jobs.append({
            "name": job_name,
            "source": source_path,
            "destination": destination_path,
            "hour": schedule_hour,
            "status": "pending"
        })

    def run_all_jobs(self):
        for job in self.backup_jobs:
            print(f"[{datetime.now()}] Starting backup: {job['name']}")

            # === BACKUP LOGIC ===
            try:
                # Simulate backup operation
                time.sleep(0.1)
                success = self._copy_data(job["source"], job["destination"])

                if success:
                    job["status"] = "completed"
                    message = f"Backup {job['name']} completed successfully"
                    self.log_entries.append({
                        "timestamp": datetime.now(),
                        "job": job["name"],
                        "level": "INFO",
                        "message": message
                    })
                    print(f"  [OK] {message}")
                else:
                    raise Exception("Copy operation returned failure")

            except Exception as e:
                job["status"] = "failed"
                error_msg = f"Backup {job['name']} FAILED: {str(e)}"

                # === LOGGING (mixed into backup logic) ===
                self.log_entries.append({
                    "timestamp": datetime.now(),
                    "job": job["name"],
                    "level": "ERROR",
                    "message": error_msg
                })
                print(f"  [FAIL] {error_msg}")

                # === EMAIL NOTIFICATION (mixed into backup logic) ===
                # This is where the design breaks.
                # Adding Slack here means modifying this exact block.
                # Adding SMS means modifying it again.
                # Every notification channel touches backup execution code.
                try:
                    email_body = (
                        f"Subject: BACKUP FAILURE ALERT\n\n"
                        f"Job: {job['name']}\n"
                        f"Source: {job['source']}\n"
                        f"Destination: {job['destination']}\n"
                        f"Error: {str(e)}\n"
                        f"Time: {datetime.now()}\n"
                    )
                    # In production this would connect to SMTP
                    # server = smtplib.SMTP(self.smtp_server, self.smtp_port)
                    # server.sendmail(self.sender_email, self.alert_email, email_body)
                    # server.quit()
                    print(f"  [EMAIL] Alert sent to {self.alert_email}")
                except Exception as email_error:
                    print(f"  [EMAIL FAIL] Could not send alert: {email_error}")

    def _copy_data(self, source, destination):
        """Simulate a backup copy operation."""
        # Simulate: 80% success rate
        import random
        return random.random() > 0.2

    def get_log(self):
        """Return all log entries."""
        return self.log_entries

    def print_summary(self):
        print("\n" + "=" * 50)
        print("  BACKUP SUMMARY")
        print("=" * 50)
        completed = sum(1 for j in self.backup_jobs if j["status"] == "completed")
        failed = sum(1 for j in self.backup_jobs if j["status"] == "failed")
        print(f"  Total jobs:    {len(self.backup_jobs)}")
        print(f"  Completed:     {completed}")
        print(f"  Failed:        {failed}")
        for entry in self.log_entries:
            level_tag = "OK" if entry["level"] == "INFO" else "FAIL"
            print(f"  [{level_tag}] {entry['message']}")
        print("=" * 50)


# ────────────────────────────────────────────────────
# Usage
# ────────────────────────────────────────────────────
if __name__ == "__main__":
    scheduler = BackupScheduler()

    scheduler.add_job("daily-db-backup", "/data/postgres", "/backup/postgres", 2)
    scheduler.add_job("config-snapshot",  "/etc/configs",   "/backup/configs",  3)
    scheduler.add_job("log-archive",      "/var/logs",      "/backup/logs",     4)

    scheduler.run_all_jobs()
    scheduler.print_summary()
