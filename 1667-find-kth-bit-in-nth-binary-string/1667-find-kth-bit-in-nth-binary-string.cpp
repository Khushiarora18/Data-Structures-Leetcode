class Solution {
public:
string invert(string str){
    for(int i=0; i<str.size(); i++){
        if(str[i] =='0'){
            str[i] = '1';
        }
        else{
            str[i] = '0';
        }
        
    }
    return str;
}
string kBit(int n){
    if(n==1) return "0";
    string s = kBit(n-1);
    string rev = invert(s);
    reverse(rev.begin(), rev.end());
    return s + "1" + rev;
}
    char findKthBit(int n, int k) {
        
        string ans = kBit(n);
        return ans[k-1];
    }
};