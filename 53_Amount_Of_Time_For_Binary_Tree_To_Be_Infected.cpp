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
private:
    int maxTime = 0;

public:
    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        return maxTime;
    }

    int traverse(TreeNode* root, int start) {
        int height = 0;
        if (root == nullptr) {
            return height;
        }
        int leftheight = traverse(root->left, start);
        int rightheight = traverse(root->right, start);
        if (root->val == start) {
            maxTime = max(leftheight, rightheight);
            height = -1;
        } else if (leftheight >= 0 && rightheight >= 0) {
            height = max(leftheight, rightheight) + 1;
        } else {
            int distance = abs(leftheight) + abs(rightheight);
            maxTime = max(maxTime, distance);
            height = min(leftheight, rightheight) - 1;
        }
        return height;
    }
};