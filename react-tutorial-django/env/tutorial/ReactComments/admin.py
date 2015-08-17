from django.contrib import admin
from ReactComments import models

# Register your models here.
class AuthorAdmin(admin.ModelAdmin):
    model = models.Author

class CommentAdmin(admin.ModelAdmin):
    model = models.Comment

admin.site.register(models.Comment, CommentAdmin)
admin.site.register(models.Author, AuthorAdmin)
