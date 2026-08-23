/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int& deepestLevel, int currLevel, int& sum) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            if (currLevel == deepestLevel) {
                sum += root->val;
                currLevel--;
            }
            if (currLevel > deepestLevel) {
                sum = root->val;
                deepestLevel = currLevel;
            }
        }
        currLevel++;
        helper(root->left, deepestLevel, currLevel, sum);
        helper(root->right, deepestLevel, currLevel, sum);
    }

    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL) return 0;
        int sum = 0;
        int starter = 1;
        helper(root, starter, 1, sum);
        return sum;
    }
};

https://leetcode.com/problems/deepest-leaves-sum/?envType=problem-list-v2&envId=breadth-first-search