from django.db import models
from time import time

def get_upload_file_name(instance, filename):
	return "uploaded_file/%s_%s" % (str(time()).replace('.','_'), filename)

# Create your models here.
class Article(models.Model):
	title = models.CharField(max_length=200)
	body = models.TextField()
	pub_date = models.DateTimeField('date published')
	likes = models.IntegerField(default=0)
	thumbnail = models.FileField(upload_to=get_upload_file_name, null=True, blank=True)

	def __str__(self):	# __unicode__ on Python 2
		return self.title

class Comment(models.Model):
	name = models.CharField(max_length=200)
	body = models.TextField()
	pub_date = models.DateTimeField('date published')
	article = models.ForeignKey(Article)