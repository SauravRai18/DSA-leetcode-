class Solution {
public:
    vector<vector<int>> result;

    void getSubset(vector<int>& nums, vector<int>& temp, int idx) {

        if(idx == nums.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        getSubset(nums, temp, idx + 1);
        temp.pop_back();
        getSubset(nums, temp, idx + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) { 
        
        vector<int> temp;
        getSubset(nums, temp, 0);
        return result;

        
    }
};