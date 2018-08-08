from django.db import models
from django.contrib.auth.models import User

class FileItem(models.Model):
    user = models.ForeignKey(
        User,
        on_delete=models.CASCADE,
        related_name='files',
        blank=True,
        null=True)
    name = models.CharField(max_length=120, null=True, blank=True)
    path = models.TextField(blank=True, null=True)
    size = models.BigIntegerField(default=0)
    file_type = models.CharField(max_length=120, null=True, blank=True)
    timestamp = models.DateTimeField(auto_now_add=True)
    updated = models.DateTimeField(auto_now=True)
    uploaded = models.BooleanField(default=False)
    active = models.BooleanField(default=True)

    @property
    def title(self):
        return str(self.name)
