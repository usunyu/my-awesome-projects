# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations
import article.models


class Migration(migrations.Migration):

    dependencies = [
        ('article', '0002_auto_20141228_0049'),
    ]

    operations = [
        migrations.AddField(
            model_name='article',
            name='thumbnail',
            field=models.FileField(null=True, upload_to=article.models.get_upload_file_name, blank=True),
            preserve_default=True,
        ),
    ]
