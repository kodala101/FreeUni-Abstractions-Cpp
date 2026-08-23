class Solution {
public:
    set<int> dfs(vector<vector<int>>& isConnected, int start) {
        set<int> visited;
        stack<int> toVisite;
        toVisite.push(start);
        while (!toVisite.empty()) {
            int p = toVisite.top();
            toVisite.pop();
            if (!visited.contains(p)) {
                visited.insert(p);
                for (int i = 0; i < isConnected[p].size(); i++) {
                    if (isConnected[p][i]) toVisite.push(i);
                }
            }
        }
        return visited;
    }

    bool ifNew(set<int>& curr, vector<set<int>>& allPro) {
        for (int i = 0; i < allPro.size(); i++) {
            if (allPro[i] == curr) return false;
        }
        return true;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int x = 0;
        vector< set<int> > allPro;
        for (int i = 0; i < isConnected.size(); i++) {
            set<int> curr = dfs(isConnected, i);
            if (ifNew(curr, allPro)) {
                x++;
                allPro.push_back(curr);
            }
        }
        return x;
    }
};

https://leetcode.com/problems/number-of-provinces/?envType=problem-list-v2&envId=breadth-first-search