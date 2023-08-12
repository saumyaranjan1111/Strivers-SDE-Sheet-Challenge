/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    
    let result = {
        toBe: function(secondVal){
            if(secondVal === val){
                return true;
            }
            else {
                throw new Error("Not Equal");
            }
        },

        notToBe: function(secondVal){
            if(secondVal !== val){
                return true;
            }
            else {
                throw new Error("Equal");
            }
        }
    }

    return result;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */