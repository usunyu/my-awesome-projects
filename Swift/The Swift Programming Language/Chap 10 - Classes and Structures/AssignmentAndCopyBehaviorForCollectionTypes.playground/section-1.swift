var ages = ["Peter": 23, "Wei": 35, "Anish": 65, "Katya": 19]
var copiedAges = ages

copiedAges["Peter"] = 24
println(ages["Peter"])
// prints "23"

var a = [1, 2, 3]
var b = a
var c = a

println(a[0])
// 1
println(b[0])
// 1
println(c[0])
// 1

a[0] = 42
println(a[0])
// 42
println(b[0])
// 42
println(c[0])
// 42

a.append(4)
a[0] = 777
println(a[0])
// 777
println(b[0])
// 42
println(c[0])
// 42

b.unshare()

b[0] = -105
println(a[0])
// 777
println(b[0])
// -105
println(c[0])
// 42

if b === c {
    println("b and c still share the same array elements.")
} else {
    println("b and c now refer to two independent sets of array elements.")
}
// prints "b and c now refer to two independent sets of array elements."

if b[0...1] === b[0...1] {
    println("These two subarrays share the same elements.")
} else {
    println("These two subarrays do not share the same elements.")
}
// prints "These two subarrays share the same elements."

var names = ["Mohsen", "Hilary", "Justyn", "Amy", "Rich", "Graham", "Vic"]
var copiedNames = names.copy()

copiedNames[0] = "Mo"
println(names[0])
// prints "Mohsen"