from django.conf.urls import patterns, include, url
from todo import views

urlpatterns = patterns('',
    # Registration of new users
    url(r'^register/$', views.RegistrationView.as_view()),

    # Todos endpoint
    url(r'^todos/$', views.TodosView.as_view()),
    url(r'^todos/(?P<todo_id>[0-9]*)$', views.TodosView.as_view()),

    # API authentication
    url(r'^oauth2/', include('provider.oauth2.urls', namespace='oauth2')),
    url(r'^api-auth/', include('rest_framework.urls', namespace='rest_framework')),
)