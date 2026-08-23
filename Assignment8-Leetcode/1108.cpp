class Solution {
public:
    string defangIPaddr(string address) {
        if (address.find(".") == string::npos) return address;
        for (int i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                if (i != 0 && i != address.length() - 1) {
                    if (address[i - 1] != '[' && address[i + 1] != ']') {
                        address = address.substr(0, i) + "[.]" + address.substr(i + 1);
                        i = 0;
                    }
                }
            }
        }
        return address;
    }
};

https://leetcode.com/problems/defanging-an-ip-address/