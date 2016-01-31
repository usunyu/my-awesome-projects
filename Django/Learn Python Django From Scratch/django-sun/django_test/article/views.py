from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from django.core.context_processors import csrf
from django.utils import timezone
from django.template.loader import get_template
from django.template import Context
from article.models import Article, Comment
from forms import ArticleForm, CommentForm


# Create your views here.
def articles(request):
	language = 'en-us'
	session_language = 'en-us'

	if 'lang' in request.COOKIES:
		language = request.COOKIES['lang']

	if 'lang' in request.session:
		session_language = request.session['lang']

	context = {
		'articles': Article.objects.all(),
		'language': language,
		'session_language': session_language
	}
	return render(request, 'articles.html', context)

def article(request, article_id=1):
	context = {'article': Article.objects.get(id=article_id)}
	return render(request, 'article.html', context)

def language(request, language='en-us'):
	response = HttpResponse("setting language to %s" % language)
	response.set_cookie('lang', language)
	request.session['lang'] = language
	return response

def create(request):
	if request.POST:
		form = ArticleForm(request.POST, request.FILES)
		if form.is_valid():
			form.save()
			
			return HttpResponseRedirect('/articles/all/')
	else:
		form = ArticleForm()

	context = {}
	context.update(csrf(request))
	context['form'] = form
	return render(request, 'create_article.html', context)

def like_article(request, article_id):
	if article_id:
		article = Article.objects.get(id=article_id)
		article.likes = article.likes + 1
		article.save()
	return HttpResponseRedirect('/articles/get/%s' % article_id)

def add_comment(request, article_id):
	article = Article.objects.get(id=article_id)

	if request.method == "POST":
		form = CommentForm(request.POST)
		if form.is_valid():
			comment = form.save(commit=False)
			comment.pub_date = timezone.now()
			comment.article = article
			comment.save()
			return HttpResponseRedirect('/articles/get/%s' % article_id)
	else:
		form = CommentForm()

	context = {}
	context.update(csrf(request))
	context['article'] = article
	context['form'] = form
	return render(request, 'add_comment.html', context)

# test demo
def hello(request):
	name = "Yu Sun"
	html = "<html><body>Hi %s, this seems to have worked!</body></html>" % name
	return HttpResponse(html)

def hello_template(request):
	name = "Yu Sun"
	context = {'name': name}
	t = get_template('hello.html')
	html = t.render(Context(context))
	return HttpResponse(html)

def hello_template_simple(request):
	name = "Yu Sun"
	context = {'name': name}
	return render(request, 'hello.html', context)