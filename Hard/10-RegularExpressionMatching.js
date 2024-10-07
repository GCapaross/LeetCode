/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 Kind cheated solution because I used a predefined library
 BUT WORKS
 */
var isMatch = function(s, p) {
    return (new RegExp(`^${p}$`)).test(s)
};
