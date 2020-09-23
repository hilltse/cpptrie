#include <string>

struct TrieNode {
    TrieNode *next[256] = {nullptr};
    bool end_word = false;

    TrieNode(bool end_word) : end_word(end_word) {}

    void insert(const std::string& s) {
        TrieNode* curr = this;

        for (char c : s) {
            if (next[c] == nullptr) {
                next[c] = new TrieNode(false);
            }
            curr = next[c];
        }

        curr->end_word = true;
    }

    bool contains(const std::string& s) {
        TrieNode* curr = this;

        for (char c : s) {
            if (next[c] == nullptr) {
                return false;
            }
            curr = next[c];
        }

        return curr->end_word;
    }
};

class Trie {
    TrieNode *root = nullptr;
public:
    void insert(const std::string& s) {
        if (root == nullptr) {
            root = new TrieNode(false);
        }

        root->insert(s);
    }

    bool contains(const std::string& s) {
        if (root == nullptr) {
            return false;
        }

        return root->contains(s);
    }

    TrieNode *take() {
        TrieNode *r = root;
        root = nullptr;
        return r;
    }
};