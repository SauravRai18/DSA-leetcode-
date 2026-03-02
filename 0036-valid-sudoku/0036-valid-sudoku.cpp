class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> s;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                char num = board[i][j];

                if (num != '.') {

                    string rowCheck = string(1, num) + " in row " + to_string(i);
                    string colCheck = string(1, num) + " in col " + to_string(j);
                    string boxCheck = string(1, num) + " in box " + to_string(i / 3) + " box " + to_string(j / 3);

                    if (s.find(rowCheck) != s.end() ||
                        s.find(colCheck) != s.end() ||
                        s.find(boxCheck) != s.end()) {
                        return false;
                    }
                    s.insert(rowCheck);
                    s.insert(colCheck);
                    s.insert(boxCheck);
                }
            }
        }
        return true;
    }
};