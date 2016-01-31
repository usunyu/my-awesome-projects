class AdminUser < ActiveRecord::Base

	has_and_belongs_to_many :pages
	has_many :section_edits
	has_many :sections, :through => :section_edits

	# attr_accessible :title, :body
	attr_accessible :first_name, :last_name, :email, :hashed_password, :username, :salt
	# to configure a different table name
	# set_table_name("admin_users")

	scope :named, lambda { |first, last| where(:first_name => first, :last_name => last) }

end
