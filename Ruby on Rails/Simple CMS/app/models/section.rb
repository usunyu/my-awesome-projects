class Section < ActiveRecord::Base

	belongs_to :page
	has_many :section_edits
	has_many :editors, :through => :section_edits, :class_name => "AdminUser"

	# attr_accessible :title, :body
	attr_accessible :page_id, :name, :position, :visible, :content_type, :content

end
