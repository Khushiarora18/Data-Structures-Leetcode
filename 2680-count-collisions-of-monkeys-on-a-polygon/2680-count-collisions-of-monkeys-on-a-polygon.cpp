class Solution {
public:
int mod = 1000000007;
long long pow(long long n){
    if(n==1) return 2;
    long long t = pow(n/2);
    if(n%2==0) return (t*t)%mod;
    return (2*(t*t)%mod)%mod;
}
    int monkeyMove(int n) {
        int t = pow(n)%mod-2;
        return(t<0)?mod+t:t;
        
    }
};