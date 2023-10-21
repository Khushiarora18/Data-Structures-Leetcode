class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
    if (digits.empty()) {
        return result;
    }
    
    vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    string current;
    backtrack(result, keypad, digits, current, 0);
    return result;
}

void backtrack(vector<string>& result, const vector<string>& keypad, const string& digits, string& current, int index) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }
    
    int digit = digits[index] - '0';
    string letters = keypad[digit];
    for (char letter : letters) {
        current.push_back(letter);
        backtrack(result, keypad, digits, current, index + 1);
        current.pop_back();
    }

        
    }
};