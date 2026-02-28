class Solution {
public:
    bool ispalindrome(string& s) {

        string t = s;

        reverse(t.begin(), t.end());

        return t == s;
    }

    void helper(vector<vector<string>>& result, vector<string>& temp,
                string s) {

        if (s.size() == 0) {

            result.push_back(temp);
            return;
        }

        for (int i = 0; i < s.size(); i++) {

            string part = s.substr(0, i + 1);

            if (ispalindrome(part)) {

                temp.push_back(part);
                helper(result, temp, s.substr(i + 1));
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<string> temp;

        helper(result, temp, s);

        return result;
    }
};
