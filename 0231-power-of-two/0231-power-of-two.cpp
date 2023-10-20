class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        return ((n==1) || (n%2==0 and isPowerOfTwo(n/2)));
        
    }
};