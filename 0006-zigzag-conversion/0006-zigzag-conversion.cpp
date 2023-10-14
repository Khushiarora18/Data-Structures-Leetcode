class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() <= numRows){
            return s;
        }
        vector<string> rows(numRows, "");
        int curRow = 0;
        bool goingDown = true;

        for(char c : s){
            rows[curRow] += c;

            if(goingDown && curRow == numRows -1){
                goingDown = false;
            }
            else if(!goingDown && curRow == 0){
                goingDown = true;
            }
            curRow += goingDown ? 1 : -1;
        }
string result;
for(const string& row : rows){
    result += row;
}
return result;
    }
};