func repeat<ItemType>(item: ItemType, times: Int) -> ItemType[] {
    var result = ItemType[]()
    for i in 0..times {
        result += item
    }
    return result
}
repeat("knock", 4)

// Reimplement the Swift standard library's optional type
enum OptionalValue<T> {
    case None
    case Some(T)
}
var possibleInteger: OptionalValue<Int> = .None
possibleInteger = .Some(100)

func anyCommonElements <T, U where T: Sequence, U: Sequence, T.GeneratorType.Element: Equatable, T.GeneratorType.Element == U.GeneratorType.Element> (lhs: T, rhs: U) -> T.GeneratorType.Element[] {
    var ret:T.GeneratorType.Element[] = []
    for lhsItem in lhs {
        for rhsItem in rhs {
            if lhsItem == rhsItem {
                ret.append(lhsItem)
            }
        }
    }
    return ret
}
anyCommonElements([1, 2, 3], [2, 3])