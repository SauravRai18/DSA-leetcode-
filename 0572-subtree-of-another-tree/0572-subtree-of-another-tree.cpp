class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q) {

        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        return (p->val == q->val) &&
               isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;

        if (isIdentical(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};