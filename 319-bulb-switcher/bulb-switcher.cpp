class Solution {
public:
    int bulbSwitch(int n) {
        // any bulb that gets odd no of times remains on
        // all the numbers which have an odd no of divisors will remain on
        // only perfect squares have an odd no of divisors
        // for any n, the answer is the no of perfect squares <= n

        return (int)sqrt(n);
    }
};