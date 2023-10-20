class Solution {
    private:
    void printSS(vector<int>nums, vector<int>curr, vector<vector<int>>&ans, int i){
        if(i>=nums.size()){
            ans.push_back(curr);
            return;
        }
        printSS(nums, curr, ans, i+1);
        curr.push_back(nums[i]);
        printSS(nums, curr, ans, i+1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>ans;
        printSS(nums, curr, ans, 0);
        return ans;
        
    }
};