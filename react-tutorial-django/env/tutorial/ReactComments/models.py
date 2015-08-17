from django.db import models

# Create your models here.
class Author(models.Model):
    name = models.CharField(max_length=150, primary_key=True)

    def __unicode__(self):
        return self.name

class Comment(models.Model):
    author = models.ForeignKey(Author, related_name="comments")
    text = models.TextField()

    def __unicode__(self):
        return self.text

