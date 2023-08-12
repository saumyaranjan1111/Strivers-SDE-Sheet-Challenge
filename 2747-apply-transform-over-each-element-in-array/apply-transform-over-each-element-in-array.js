/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let result = arr;
    for(let i = 0; i<arr.length; i++){
        result[i] = fn(arr[i], i);
    }
    return result;
};