from rest_framework import viewsets
from ReactComments import models

class CommentViewSet(viewsets.ModelViewSet):
    model = models.Comment

    def create(self, request, *args, **kwargs):
        if "author" in request.DATA:
            author_pk = request.DATA.get("author")
            author_list = models.Author.objects.filter(name=author_pk)
            if len(author_list) == 0:
                author = models.Author(name=author_pk)
                author.save()
        return super(CommentViewSet, self).create(request, *args, **kwargs)

class AuthorViewSet(viewsets.ModelViewSet):
    model = models.Author
