"""
Logger module. Handles only logging. Nothing else.

PRINCIPLE: Single Responsibility
  This module has one reason to change — if logging requirements change
  (format, destination, rotation). It never changes because of backup
  logic or notification logic.
"""

from datetime import datetime


class BackupLogger:
    """Records structured log entries for backup operations."""

    def __init__(self):
        self.entries = []

    def info(self, job_name, message):
        self._log(job_name, "INFO", message)

    def error(self, job_name, message):
        self._log(job_name, "ERROR", message)

    def _log(self, job_name, level, message):
        entry = {
            "timestamp": datetime.now(),
            "job": job_name,
            "level": level,
            "message": message
        }
        self.entries.append(entry)
        tag = "OK" if level == "INFO" else "FAIL"
        print(f"  [{tag}] {message}")

    def get_entries(self):
        return list(self.entries)
