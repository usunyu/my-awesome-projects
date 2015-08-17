from django.conf.urls import patterns, url, include
from ReactComments import views, routers

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'tutorial.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^$', views.HomePageView.as_view(), name='index'),
    url(r'^api/v1/', include(routers.api_router.urls)),
    url(r'^api/v1/auth/', include('rest_framework.urls', namespace='rest_framework'))
)
