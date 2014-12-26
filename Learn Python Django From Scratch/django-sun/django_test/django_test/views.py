from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.contrib import auth
from django.core.context_processors import csrf
from django.contrib.auth.forms import UserCreationForm

def login(request):
	context = {}
	context.update(csrf(request))
	return render(request, 'login.html', context)

def auth_view(request):
	username = request.POST.get('username', '')
	password = request.POST.get('password', '')
	user = auth.authenticate(username=username, password=password)

	if user is not None:
		auth.login(request, user)
		return HttpResponseRedirect('/accounts/loggedin')
	else:
		return HttpResponseRedirect('/accounts/invalid')

def loggedin(request):
	context = {'full_name': request.user.username}
	return render(request, 'loggedin.html', context)

def logout(request):
	auth.logout(request)
	return render(request, 'logout.html')

def invalid_login(request):
	return render(request, 'invalid_login.html')

def register_user(request):
	if request.method == 'POST':
		form = UserCreationForm(request.POST)
		if form.is_valid():
			form.save()
			return HttpResponseRedirect('/accounts/register_success')

	context = {}
	context.update(csrf(request))

	context['form'] = UserCreationForm()

	return render(request, 'register.html', context)

def register_success(request):
	return render(request, 'register_success.html')