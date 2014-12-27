from django.conf.urls import patterns, include, url

urlpatterns = patterns('',
	# Examples:
	# url(r'^$', 'django_test.views.home', name='home'),
	# url(r'^blog/', include('blog.urls')),

    url(r'^hello/$', 'article.views.hello'),
    url(r'^hello_template/$', 'article.views.hello_template'),
    url(r'^hello_template_simple/$', 'article.views.hello_template_simple'),

	url(r'^all/$', 'article.views.articles'),
	url(r'^get/(?P<article_id>\d+)/$', 'article.views.article'),
	url(r'^language/(?P<language>[a-z\-]+)/$', 'article.views.language'),
	url(r'^create/$', 'article.views.create'),
)
