class Solution {
    private:
    void permute(int index, vector<int>&arr, vector<vector<int>>&ans){
        if(index == arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i= index; i<arr.size(); i++){
            swap(arr[index], arr[i]);
            permute(index+1, arr, ans);
            swap(arr[index], arr[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permute(0, nums, ans);
        return ans;
    }
};