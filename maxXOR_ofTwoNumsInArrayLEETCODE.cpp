// this problem is maximum xor of two elements of the array, implemented efficiently using trie data structure,
// it is very important to understand the concepts of implementing trie data structures.

class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = NULL;
        child[1] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {

        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (node->child[bit] == NULL)
                node->child[bit] = new TrieNode();

            node = node->child[bit];
        }
    }

    int getMax(int num) {

        TrieNode* node = root;

        int ans = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            int opposite = 1 - bit;

            if (node->child[opposite]) {

                ans |= (1 << i);

                node = node->child[opposite];
            }
            else {
                node = node->child[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        for (int num : nums)
            trie.insert(num);

        int ans = 0;

        for (int num : nums)
            ans = max(ans, trie.getMax(num));

        return ans;
    }
};