class Solution {
public:
    void recoverTree (TreeNode* root)
    {
        pair<TreeNode*, TreeNode*> broken;
        TreeNode* prev = NULL;
        TreeNode* current = root;

        while (current != NULL) {
            if (current->left == NULL) {
                detect (broken, prev, current);
                prev = current;
                current = current->right;
            }
            else {
                auto node = current->left;

                while (node->right != NULL and node->right != current)
                    node = node->right;

                if (node->right == NULL) {
                    node->right = current;
                    current = current->left;
                }
                else {
                    detect (broken, prev, current);
                    node->right = NULL;
                    prev = current;
                    current = current->right;
                }
            }
        }

        swap (broken.first->val, broken.second->val);
    }

    void detect (pair<TreeNode*, TreeNode*>& broken,
                 TreeNode* prev, TreeNode* current)
    {
        if (prev != NULL and prev->val > current->val) {
            if (broken.first == NULL)
                broken.first = prev;

            broken.second = current;
        }
    }
};
 
//naive version:
 class Solution {
public:
    void recoverTree (TreeNode* root)
    {
        vector<TreeNode*> seq;
        inorder (root, back_inserter (seq));

        auto first = begin (seq);

        while ((*first)->val < (*next (first))->val)
            ++first;

        auto second = prev (end (seq));

        while ((*prev (second))->val < (*second)->val)
            --second;

        swap ((*first)->val, (*second)->val);
    }

    template<typename OutIt>
    void inorder (TreeNode* root, OutIt output)
    {
        if (root == NULL)
            return;

        inorder (root->left, output);
        *output++ = root;
        inorder (root->right, output);
    }
};
