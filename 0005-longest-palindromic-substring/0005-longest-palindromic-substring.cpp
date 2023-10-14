class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0; 
        int end = 0;

        for(int center = 0; center < n; center++){
            int left = center, right = center;
            while(left >=0 && right < n && s[left] == s[right]){
                if(right - left > end - start){
                    start = left;
                    end = right;
                }
                left--;
                right++;
            }
            left = center;
            right = center + 1;

            while(left >= 0 && right < n && s[left] == s[right]){
                if(right-left > end - start){
                    start = left;
                    end = right;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, end-start+1);
    }
};