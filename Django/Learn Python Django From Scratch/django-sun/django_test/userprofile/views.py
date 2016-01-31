from django.shortcuts import render
from django.http import HttpResponseRedirect
from django.core.context_processors import csrf
from django.contrib.auth.decorators import login_required

from forms import UserProfileForm

# Create your views here.
@login_required
def user_profile(request):
	if request.POST:
		form = UserProfileForm(request.POST, instance=request.user.profile)
		if form.is_valid():
			form.save()
			return HttpResponseRedirect('/accounts/loggedin')
	else:
		user = request.user
		profile = user.profile
		form = UserProfileForm(instance=profile)

	context = {}
	context.update(csrf(request))
	context['form'] = form
	return render(request, 'profile.html', context)