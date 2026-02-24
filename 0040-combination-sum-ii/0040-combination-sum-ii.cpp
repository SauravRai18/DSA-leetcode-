class Solution {
public:
    void helper(vector<int>& arr, int target, vector<vector<int>>& ans,
                vector<int>& temp, int idx) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {

            if (i > idx && arr[i] == arr[i - 1])
                continue;

            if(arr[i] > target){
                break;
            }
            
            temp.push_back(arr[i]);

            helper(arr, target - arr[i], ans, temp, i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        vector<int> temp;

        helper(arr, target, ans, temp, 0);

        return ans;
    }
};