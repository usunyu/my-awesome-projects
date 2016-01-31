from django import forms
from models import UserProfile

class UserProfileForm(forms.ModelForm):
	class Meta:
		model = UserProfile
		fields = ('likes_cheese', 'favorite_hamster_name')