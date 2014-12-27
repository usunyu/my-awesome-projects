from django import forms
from models import Article

class ArticleForm(forms.ModelForm):

	class Meta:
		model = Article
		fields = ('title', 'body', 'pub_date')