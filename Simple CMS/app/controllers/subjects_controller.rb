class SubjectsController < ApplicationController

	layout 'admin'

	def index
		list
		render("list")
	end

	def list
		@subjects = Subject.order("subjects.position ASC")
	end

	def show
		@subject = Subject.find(params[:id])
	end

	def new
		@subject = Subject.new(:name => "default")
		@subject_count = Subject.count + 1
	end

	def create
		# Instantiate a new object using form parameters
		@subject = Subject.new(params[:subject])
    	# Save the object
    	if @subject.save
			# If save succeeds, redirect to the list action
			flash[:notice] = "Subject created."
			redirect_to(:action => "list")
		else
      		# If save fails, redisplay the form so user can fix problems
      		@subject_count = Subject.count + 1
      		render("new")
      	end
	end

	def edit
		@subject = Subject.find(params[:id])
		@subject_count = Subject.count
	end

	def update
		# Find object using form parameters
		@subject = Subject.find(params[:id])
    	# Update the object
    	if @subject.update_attributes(params[:subject])
			# If update succeeds, redirect to the list action
			flash[:notice] = "Subject updated."
			redirect_to(:action => "show", :id => @subject.id)
		else
      		# If save fails, redisplay the form so user can fix problems
      		@subject_count = Subject.count
      		render("edit")
      	end
	end

	def delete
		@subject = Subject.find(params[:id])
	end

	def destroy
		Subject.find(params[:id]).destroy
		flash[:notice] = "Subject destroyed."
		redirect_to(:action => 'list')
	end

end
