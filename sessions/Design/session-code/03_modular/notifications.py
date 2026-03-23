"""
Calsoft Engineering Internship 2026
Session: Software Design Principles and Engineering Workflow


NOTIFICATION MODULE

This is the notification interface and its implementations.
The scheduler does not know or care which notification channels exist.
It calls the interface. The interface routes to the right channel.

PRINCIPLES VISIBLE HERE:
  - Single Responsibility: each notifier does one thing
  - Open/Closed: adding SMS required zero changes to scheduler or existing notifiers
  - Dependency Inversion: scheduler depends on NotificationService (abstraction),
    not on EmailNotifier (concrete implementation)
"""

from abc import ABC, abstractmethod
from datetime import datetime


class Notifier(ABC):
    """Abstract interface. Any notification channel implements this."""

    @abstractmethod
    def send(self, job_name, error_message, details):
        pass


class EmailNotifier(Notifier):
    """Sends failure alerts via email."""

    def __init__(self, smtp_server, sender, recipient):
        self.smtp_server = smtp_server
        self.sender = sender
        self.recipient = recipient

    def send(self, job_name, error_message, details):
        email_body = (
            f"Subject: BACKUP FAILURE ALERT\n\n"
            f"Job: {job_name}\n"
            f"Error: {error_message}\n"
            f"Time: {details.get('timestamp', datetime.now())}\n"
        )
        # In production: smtplib.SMTP connection here
        print(f"  [EMAIL] Alert for '{job_name}' sent to {self.recipient}")


class SlackNotifier(Notifier):
    """Sends failure alerts to a Slack channel."""

    def __init__(self, webhook_url, channel):
        self.webhook_url = webhook_url
        self.channel = channel

    def send(self, job_name, error_message, details):
        # In production: HTTP POST to Slack webhook
        print(f"  [SLACK] Alert for '{job_name}' posted to #{self.channel}")


class SmsNotifier(Notifier):
    """Sends SMS alerts for critical failures."""

    def __init__(self, phone_number):
        self.phone_number = phone_number

    def send(self, job_name, error_message, details):
        # In production: Twilio or similar API call
        print(f"  [SMS] Critical alert for '{job_name}' sent to {self.phone_number}")


class NotificationService:
    """
    Routes failure alerts to all registered notification channels.
    The scheduler calls this. It does not know what channels exist.
    """

    def __init__(self):
        self.notifiers = []

    def register(self, notifier):
        """Register a notification channel."""
        self.notifiers.append(notifier)

    def notify_failure(self, job_name, error_message, details=None):
        """Send failure alert through all registered channels."""
        if details is None:
            details = {}
        details["timestamp"] = datetime.now()

        for notifier in self.notifiers:
            try:
                notifier.send(job_name, error_message, details)
            except Exception as e:
                print(f"  [NOTIFY FAIL] {type(notifier).__name__}: {e}")
