class DemoController < ApplicationController

  layout 'admin'

  def index
  	# render('demo/hello')
  	# redirect_to(:action => 'other_hello')
  end

  def hello
  	# redirect_to('http://www.lynda.com')
    @array = [1, 2, 3, 4, 5]
    @id = params[:id]
    @page = params[:page]
  end

  def other_hello
  	render(:text => 'Hello Everyone!')
  end

  def javascript
    
  end

  def text_helper

  end

end
