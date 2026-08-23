class Solution {
public:
    bool isPalindrome(string s) {
        string good = "";
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i]) || isdigit(s[i])) good += tolower(s[i]);
        }

        string reversed = "";
        for (int j = good.length() - 1; j >= 0; j--) reversed += good[j];

        if (good == reversed) return true;
        return false;
    }
};

https://leetcode.com/problems/valid-palindrome/?envType=problem-list-v2&envId=string