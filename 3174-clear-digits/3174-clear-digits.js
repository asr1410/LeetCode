/**
 * @param {string} s
 * @return {string}
 */
var clearDigits = function(s) {
    let result = [];
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (result.length > 0) {
                result.pop();
            }
        } else {
            result.push(s[i]);
        }
    }
    
    return result.join('');
};
