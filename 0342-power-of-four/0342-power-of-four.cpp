class Solution {
    public:
    int x;
    bool check(){
        if(x>0 and x%4 == 0){
            x = x/4;
            return check();
        }
        else{
            return x ==1;
        }
    }
public:
    bool isPowerOfFour(int n) {
        x = n;
        return check();
    }
};