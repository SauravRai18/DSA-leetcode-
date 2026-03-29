class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.size() > s.size()) return "";

        unordered_map<char, int> mp;

        for (auto ch : t) {

            mp[ch]++;
        }

        int minLen = INT_MAX;

        int left = 0;

        int start = 0;

        int count = t.size();

        for (int right = 0; right < s.size(); right++) {

            if (mp[s[right]] > 0) {
                count--;
            }

            mp[s[right]]--;

            while (count == 0) {

                if ((right - left + 1) < minLen) {

                    minLen = right - left + 1;

                    start = left;
                }

                mp[s[left]]++;

                if (mp[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {

            return "";
        }

        return s.substr(start, minLen);
    }
};