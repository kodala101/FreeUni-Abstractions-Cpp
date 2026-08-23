class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> sth;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                sth.push_back(sth[sth.size() - 1] + sth[sth.size() - 2]);
            }
            else if (operations[i] == "D") {
                sth.push_back(2 * sth[sth.size() - 1]);
            }
            else if (operations[i] == "C") {
                sth.pop_back();
            }
            else {
                int y = 0;
                if (operations[i][0] == '-') {
                    for (int j = 1; j < operations[i].length(); j++) {
                        y = y * 10 + (operations[i][j] - '0');
                    }
                    y *= -1;
                }
                else {
                    for (int j = 0; j < operations[i].length(); j++) {
                        y = y * 10 + (operations[i][j] - '0');
                    }
                }
                sth.push_back(y);
            }
        }
        int sum = 0;
        for (int y : sth) sum += y;
        return sum;
    }
};

https://leetcode.com/problems/baseball-game/?envType=problem-list-v2&envId=stack