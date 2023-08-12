/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    const initialValue = init;

    let result = {
        increment: function(){
            init++;
            return init;
        },
        decrement: function(){
            init--;
            return init;
        }, 
        reset: function(){
            init = initialValue;
            return init;
        }
    }

    return result;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */