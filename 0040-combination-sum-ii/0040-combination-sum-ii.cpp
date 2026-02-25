class Solution {
public:
    void helper(vector<int>& candidates, int target,
                vector<vector<int>>& result, vector<int>& temp, int idx) {

        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (target < 0 || idx == candidates.size()) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            temp.push_back(candidates[i]);
            helper(candidates, target - candidates[i], result, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> temp;
        helper(candidates, target, result, temp, 0);

        return result;
    }
};