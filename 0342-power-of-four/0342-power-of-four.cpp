class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        return((n==1) || (n%4==0 and isPowerOfFour(n/4)));
        
    }
};