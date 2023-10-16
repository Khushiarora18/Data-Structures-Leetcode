class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> tempRow;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    tempRow.push_back(1);
                } else {
                    int sum = row[j - 1] + row[j];
                    tempRow.push_back(sum);
                }
            }
            row = tempRow;
        }
        
        return row;
    }
};
