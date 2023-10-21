class Solution {
    private:
    void permuteUnique(vector<int>&nums, set<vector<int>>&set, vector<int>temp, int ind){
        if(ind == nums.size()){
            set.insert(temp);
            return;
        }
        for(int i= ind; i<temp.size(); i++){
            swap(temp[ind], temp[i]);
            permuteUnique(nums,set, temp, ind+1);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        set<vector<int>> set;
        permuteUnique(nums, set, temp, 0);
        for(auto it : set){
            ans.push_back(it);
        }
        return ans;
        
    }
};