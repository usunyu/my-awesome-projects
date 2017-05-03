class Subject < ActiveRecord::Base

	has_many :pages

	validates_presence_of :name
	
	# attr_accessible :title, :body
	attr_accessible :name, :position, :visible

	scope :visible, where(:visible => true)
	scope :invisible, where(:visible => false)
	scope :search, lambda { |query| where(["name LIKE ?", "%#{query}%"]) }

end
