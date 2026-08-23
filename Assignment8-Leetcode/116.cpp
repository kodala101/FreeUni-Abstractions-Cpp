/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        vector<Node*> row;
        int depth = 0;
        while (!q.empty()) {
            int x = q.size();
            for (int i = 0; i < x; i++) {
                Node* n = q.front();
                row.push_back(n);
                q.pop();
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
            depth++;
        }

        for (int j = 0; j < depth; j++) {
            int last = 0;
            for (int h = 0; h <= j; h++) last += pow(2, h);
            if (j == 0) last = 1;
            for (int k = pow(2, j) - 1; k < last; k++) {
                if (k == last - 1) {
                    row[k]->next = NULL;
                    break;
                }
                row[k]->next = row[k + 1];
            }
        }
        return row[0];
    }
};

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/?envType=problem-list-v2&envId=breadth-first-search