let names = ["Chris", "Alex", "Ewa", "Barry", "Daniella"]

func backwards(s1: String, s2: String) -> Bool {
    return s1 > s2
}
var reversed = sort(names, backwards)
// reversed is equal to ["Ewa", "Daniella", "Chris", "Barry", "Alex"]

reversed = sort(names, { (s1: String, s2: String) -> Bool
    in
    return s1 > s2
})

reversed = sort(names, { s1, s2 in return s1 > s2 } )

reversed = sort(names, { s1, s2 in s1 > s2 } )

reversed = sort(names, { $0 > $1 } )

reversed = sort(names, >)