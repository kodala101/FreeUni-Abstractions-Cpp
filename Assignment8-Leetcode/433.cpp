class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> geness;
        geness.push_back('A');
        geness.push_back('C');
        geness.push_back('G');
        geness.push_back('T');
        if (startGene == endGene) return 0;
        queue<string> q;
        set<string> used;
        q.push(startGene);
        used.insert(startGene);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;

            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();

                for (int k = 0; k < geness.size(); k++) {
                    for (int j = 0; j < curr.length(); j++) {
                        string copy = curr;
                        copy[j] = geness[k];
                        if (find(bank.begin(), bank.end(), copy) == bank.end() || used.contains(copy)) continue;
                        if (copy == endGene) return level;
                        q.push(copy);
                        used.insert(copy);
                    }
                }
            }
        }
        return -1;
    }
};

https://leetcode.com/problems/minimum-genetic-mutation/