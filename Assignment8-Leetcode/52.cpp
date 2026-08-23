class Solution {
public:
    bool canPlace(vector< vector<bool> >& grid, int i, int j, int n) {
        for (int x = 0; x < grid[i].size(); x++) {
            if (grid[i][x]) return false;
        }
        for (int y = 0; y < grid.size(); y++) {
            if (grid[y][j]) return false;;
        }
        for (int h = -(n - 1); h < n; h++) {
            if (i + h >= 0 && i + h < grid.size() && j + h >= 0 && j + h < grid.size()) {
                if (grid[i + h][j + h]) return false;
            }
            if (i - h >= 0 && i - h < grid.size() && j - h >= 0 && j - h < grid.size()) {
                if (grid[i - h][j - h]) return false;
            }
            if (i + h >= 0 && i + h < grid.size() && j - h >= 0 && j - h < grid.size()) {
                if (grid[i + h][j - h]) return false;
            }
            if (i - h >= 0 && i - h < grid.size() && j + h >= 0 && j + h < grid.size()) {
                if (grid[i - h][j + h]) return false;
            }
        }
        return true;
    }

    void helper(int& x, vector< vector<bool> >& grid, int i, int n) {
        if (i == grid[0].size()) {
            x++;
            return;
        }
        for (int j = 0; j < grid[i].size(); j++) {
            if (canPlace(grid, i, j, n)) {
                grid[i][j] = true;
                helper(x, grid, i + 1, n);
                grid[i][j] = false;
            }
        }
    }

    int totalNQueens(int n) {
        vector< vector<bool> > grid(n, vector<bool>(n, false));
        int x = 0;
        helper(x, grid, 0, n);
        return x;
    }
};

https://leetcode.com/problems/n-queens-ii/