from rest_framework import serializers
from ReactComments import models

class CommentSerializer(serializers.ModelSerializer):
    class Meta:
        model = models.Comment
        depth = 1
