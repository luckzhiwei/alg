#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        } else {
            return getMinDepth(root);
        }
    }

    int getMinDepth(TreeNode *node) {
        if (node->left == NULL && node->right == NULL) {
            return 1;
        } else if (node->left == NULL) {
            return 1 + getMinDepth(node->right);
        } else if (node->right == NULL) {
            return 1 + getMinDepth(node->left);
        } else {
            return min(1 + getMinDepth(node->left), 1 + getMinDepth(node->right));
        }

    }
};

int main() {
    Solution sl;

    int a;

}