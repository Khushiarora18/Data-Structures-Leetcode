class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sResult = processString(s);
        string tResult = processString(t);
        
        return sResult == tResult;
    }

private:
    string processString(const string& input) {
        string result;
        
        for (char ch : input) {
            if (ch == '#') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result += ch;
            }
        }
        
        return result;
    }
};
