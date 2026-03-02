class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int>st(nums.begin(), nums.end());

        int longest = 0;

        for(auto &it : st){

            if(st.find(it - 1) == st.end()){

                int start = it;
                int currenlongest = 1;

                while(st.find(start + 1) != st.end()){

                    start++;
                    currenlongest++;
                }

                longest = max(longest, currenlongest);
            }


        }
        return longest;
    }
};