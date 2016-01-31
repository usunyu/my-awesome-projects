class Page < ActiveRecord::Base

	belongs_to :subject
	has_many :sections
	has_and_belongs_to_many :editors, :class_name => "AdminUser"

	# attr_accessible :title, :body
	attr_accessible :subject_id, :name, :position, :permalink, :visible

end
