class CreatePages < ActiveRecord::Migration
  def change
    create_table :pages do |t|
    	t.integer "subject_id"
    	# can also use: t.references :subject
    	t.string "name"
    	t.string "permalink"
    	t.integer "position"
    	t.boolean "visible", :default => false
    	t.timestamps
    end
    add_index("pages", "subject_id")
    add_index("pages", "permalink")
  end
end
