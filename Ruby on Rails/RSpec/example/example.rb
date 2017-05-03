# 13.2 Built-in Matchers

# Equality: Object Equivalence and Object Identity
a.should == b
a.should === b
a.should eql(b)
a.should equal(b)

(3 * 5).should == 15

person = Person.new(:given_name => "Yukihiro", :family_name => "Matsumoto")
person.full_name.should == "Yukihiro Matsumoto"
person.nickname.should == "Matz"

person = Person.create!(:name => "David")
Person.find_by_name("David").should equal(person)

# Do Not Use !=
actual.should == expected
actual.should_not == expected

# Floating-Point Calculations
result.should be_close(5.25, 0.005)

# Multiline Text
expected = File.open('expected_statement.txt','r') do |f|
	f.read
end
account.statement.should == expected

# Ch, ch, ch, ch, changes
assert_difference 'User.admins.count', 1 do
	User.create!(:role => "admin")
end

expect {
	User.create!(:role => "admin")
}.to change{ User.admins.count }

expect {
	User.create!(:role => "admin")
}.to change{ User.admins.count }.by(1)
expect {
	User.create!(:role => "admin")
}.to change{ User.admins.count }.to(1)
expect {
	User.create!(:role => "admin")
}.to change{ User.admins.count }.from(0).to(1)

expect {
	seller.accept Offer.new(250_000)
}.to change{agent.commission}.by(7_500)
agent.commission.should == 0
seller.accept Offer.new(250_000)
agent.commission.should == 7_500

# Expecting Errors
account = Account.new 50, :dollars
expect {
	account.withdraw 75, :dollars
}.to raise_error(
	InsufficientFundsError,
	/attempted to withdraw 75 dollars from an account with 50 dollars/
)
expect {
	account.withdraw 75, :dollars
}.to raise_error(
	"attempted to withdraw 75 dollars from an account with 50 dollars"
)
expect {
	account.withdraw 75, :dollars
}.to raise_error(/attempted to withdraw 75 dollars/)
expect {
	account.withdraw 75, :dollars
}.to raise_error(InsufficientFundsError)

expect {
	account.withdraw 75, :dollars
}.to raise_error(
	InsufficientFundsError,
	"attempted to withdraw 75 dollars from an account with 50 dollars"
)
expect {
	account.withdraw 75, :dollars
}.to raise_error(
	InsufficientFundsError,
	/attempted to withdraw 75 dollars/
)

