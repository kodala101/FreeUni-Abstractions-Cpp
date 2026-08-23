class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        if (s.length() == 0 || s.length() == 1) return sum;
        for (int i = 0; i < s.length(); i++) {
            if (i != s.length() - 1) {
                int par = s[i] - s[i + 1];
                if (par < 0) par *= -1;
                sum += par;
            }
        }
        return sum;
    }
};

https://leetcode.com/problems/score-of-a-string/