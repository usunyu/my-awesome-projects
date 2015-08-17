from rest_framework import routers
from ReactComments import api_views

# Routers provide an easy way of automatically determining the URL conf.
api_router = routers.DefaultRouter()
api_router.register(r'comments', api_views.CommentViewSet)
