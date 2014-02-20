# This file is auto-generated from the current state of the database. Instead
# of editing this file, please use the migrations feature of Active Record to
# incrementally modify your database, and then regenerate this schema definition.
#
# Note that this schema.rb definition is the authoritative source for your
# database schema. If you need to create the application database on another
# system, you should be using db:schema:load, not running all the migrations
# from scratch. The latter is a flawed and unsustainable approach (the more migrations
# you'll amass, the slower it'll run and the greater likelihood for issues).
#
# It's strongly recommended to check this file into your version control system.

ActiveRecord::Schema.define(:version => 20130625042005) do

  create_table "admin_users", :force => true do |t|
    t.string   "first_name",      :limit => 25
    t.string   "last_name",       :limit => 50
    t.string   "email",           :limit => 100, :default => "", :null => false
    t.string   "hashed_password", :limit => 40
    t.datetime "created_at",                                     :null => false
    t.datetime "updated_at",                                     :null => false
    t.string   "username",        :limit => 25
    t.string   "salt",            :limit => 40
  end

  add_index "admin_users", ["username"], :name => "index_admin_users_on_username"

  create_table "admin_users_pages", :id => false, :force => true do |t|
    t.integer "admin_user_id"
    t.integer "page_id"
  end

  add_index "admin_users_pages", ["admin_user_id", "page_id"], :name => "index_admin_users_pages_on_admin_user_id_and_page_id"

  create_table "pages", :force => true do |t|
    t.integer  "subject_id"
    t.string   "name"
    t.string   "permalink"
    t.integer  "position"
    t.boolean  "visible",    :default => false
    t.datetime "created_at",                    :null => false
    t.datetime "updated_at",                    :null => false
  end

  add_index "pages", ["permalink"], :name => "index_pages_on_permalink"
  add_index "pages", ["subject_id"], :name => "index_pages_on_subject_id"

  create_table "section_edits", :force => true do |t|
    t.integer  "admin_user_id"
    t.integer  "section_id"
    t.string   "summary"
    t.datetime "created_at",    :null => false
    t.datetime "updated_at",    :null => false
  end

  add_index "section_edits", ["admin_user_id", "section_id"], :name => "index_section_edits_on_admin_user_id_and_section_id"

  create_table "sections", :force => true do |t|
    t.integer  "page_id"
    t.string   "name"
    t.integer  "position"
    t.boolean  "visible",      :default => false
    t.string   "content_type"
    t.text     "content"
    t.datetime "created_at",                      :null => false
    t.datetime "updated_at",                      :null => false
  end

  add_index "sections", ["page_id"], :name => "index_sections_on_page_id"

  create_table "subjects", :force => true do |t|
    t.string   "name"
    t.integer  "position"
    t.boolean  "visible",    :default => false
    t.datetime "created_at",                    :null => false
    t.datetime "updated_at",                    :null => false
  end

end
