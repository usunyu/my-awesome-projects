from django.shortcuts import render
from django.http import HttpResponse
from django.template.loader import get_template
from django.template import Context

from article.models import Article

# Create your views here.
def articles(request):
	context = {'articles': Article.objects.all()}
	return render(request, 'article/articles.html', context)

def article(request, article_id=1):
	context = {'article': Article.objects.get(id=article_id)}
	return render(request, 'article/article.html', context)

# test demo
def hello(request):
	name = "Yu Sun"
	html = "<html><body>Hi %s, this seems to have worked!</body></html>" % name
	return HttpResponse(html)

def hello_template(request):
	name = "Yu Sun"
	context = {'name': name}
	t = get_template('article/hello.html')
	html = t.render(Context(context))
	return HttpResponse(html)

def hello_template_simple(request):
	name = "Yu Sun"
	context = {'name': name}
	return render(request, 'article/hello.html', context)