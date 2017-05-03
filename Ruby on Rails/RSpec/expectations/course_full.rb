course = Course.new(:seats => 20)
20.times { course.register Student.new }
lambda {
	course.register Student.new
}.should throw_symbol(:course_full)

course = Course.new(:seats => 20)
20.times { course.register Student.new }
lambda {
	course.register Student.new
}.should throw_symbol(:course_full, 20)

