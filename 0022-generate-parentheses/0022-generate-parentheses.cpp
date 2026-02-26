class Solution {
public:

    void helper(string current, int open, int close,  vector<string>& result){

        if(open == 0 && close == 0){
            result.push_back(current);
            return;
        }

        if(open > 0){
            helper(current + '(', open - 1, close, result);

        }

        if(close > open){
             helper(current + ')', open, close - 1, result);

        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        helper("", n , n, result);
        return result;
        
    }
};