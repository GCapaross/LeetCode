func minLength(s string) int {
    var oldLen = len(s)
    for true {
        s = strings.Replace(s, "AB", "", -1)
        s = strings.Replace(s, "CD", "", -1)
        
        if oldLen == len(s) {
            break
        }

        oldLen = len(s)
    }
    return len(s)
}
