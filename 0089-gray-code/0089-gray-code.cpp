class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;  // Initialize a vector to store the Gray code sequence
        ans.push_back(0); // Gray code sequence always starts with 0
        
        // If n is 0, there's no need to continue, so return the result
        if (n == 0) {
            return ans;
        }

        ans.push_back(1); // Gray code sequence also starts with 1 for n = 1

        int curr = 1; // Initialize the current bit value
        
        // Iterate from 2 to n to generate the Gray code sequence for higher values of n
        for (int i = 2; i <= n; i++) {
            curr *= 2; // Double the current bit value

            // Iterate in reverse through the previously generated Gray code
            // and add the current bit value to each element to create the new sequence
            for (int j = ans.size() - 1; j >= 0; j--) {
                ans.push_back(curr + ans[j]);
            }
        }
        return ans; // Return the complete Gray code sequence
    }
};
