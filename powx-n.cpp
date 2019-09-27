
// https://leetcode.com/problems/powx-n
class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0)
            return 1 / myPow(x, -n);
        if (n == 0)
            return 1;
        if (n % 2 != 0)
            return x * myPow(x, n - 1);
        else{
        double tmp = myPow(x, n / 2);
        return tmp * tmp;
        }
    }
};
