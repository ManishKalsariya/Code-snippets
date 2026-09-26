#include<bits/stdc++.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Records nodes in preorder while preserving missing children.
    void serializeHelper(TreeNode* root, string& data) {
        // Record a marker when the current child is missing.
        if (root == nullptr) {
            data += "#,";
            return;
        }
 
        data += to_string(root->val) + ",";
 
        serializeHelper(root->left, data);
        serializeHelper(root->right, data);
    }
 
    // Reconstructs one subtree from the preorder token sequence.
    TreeNode* deserializeHelper(
        vector<string>& tokens,
        int& index
    ) {
        // A null marker means this child does not exist.
        if (tokens[index] == "#") {
            index++;
            return nullptr;
        }
 
        TreeNode* root = new TreeNode(
            stoi(tokens[index++]);
        );
 
        // Preorder stores the left subtree before the right subtree.
        root->left = deserializeHelper(tokens, index);
        root->right = deserializeHelper(tokens, index);
 
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        serializeHelper(root, data);
        return data;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string token;
        stringstream ss(data);
 
        // Separate the serialized string into individual tokens.
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
 
        int index = 0;
 
        return deserializeHelper(tokens, index);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));