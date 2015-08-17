react-tutorial-django
=====================

The [React tutorial](http://facebook.github.io/react/docs/tutorial.html) with a Django backend implementation. 

This follows the steps in the tutorial quite closely. The extra features are to add Django-backed API endpoints, so that React can render and post actual comments.

This also adds in PyReact and django-pipeline, so that the JSX is compiled by the server when ``./manage.py collectstatic`` is run. 

