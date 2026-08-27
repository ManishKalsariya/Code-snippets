// Leetcode problem #: 1022 - Cousins in Binary Trees II

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        
        // Root has no cousins, so its value is always 0
        root->val = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> currentLevelNodes;
            int nextLevelSum = 0;

            // Step 1: Process current level and calculate sum of all children (next level)
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                currentLevelNodes.push_back(curr);

                if (curr->left) {
                    q.push(curr->left);
                    nextLevelSum += curr->left->val;
                }
                if (curr->right) {
                    q.push(curr->right);
                    nextLevelSum += curr->right->val;
                }
            }

            // Step 2: Update children values for the next level
            // Formula: Cousin Sum = nextLevelSum - Sibling Sum
            for (TreeNode* node : currentLevelNodes) {
                int siblingSum = 0;
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                if (node->left) node->left->val = nextLevelSum - siblingSum;
                if (node->right) node->right->val = nextLevelSum - siblingSum;
            }
        }

        return root;
    }
};