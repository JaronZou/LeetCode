/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    struct Node {
        Node* (nexts[26]);
        bool end;
        Node() : end(false) {
            for(int i = 0; i < 26; ++i) {
                nexts[i] = nullptr;
            }
        }
    };
    struct Node *root;

public:
    Trie() {
        root = new Node;
    }

    void deleteAllNode(Node *root) {
        if(root == nullptr) {
            return;
        }
        for(int i = 0; i < 26; ++i) {
            if(root->nexts[i] != nullptr) {
                deleteAllNode(root->nexts[i]);
            }
        }
        delete root;
    }

    ~Trie() {
        deleteAllNode(root);
    }
    
    void insert(string word) {
        if(word.size() == 0) {
            return;
        }
        Node *cur = root;
        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if(cur->nexts[index] == nullptr) {
                cur->nexts[index] = new Node;
            }
            cur = cur->nexts[index];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Node *cur = root;
        for(int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if(cur->nexts[index] == nullptr) {
                return false;
            }
            cur = cur->nexts[index];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node *cur = root;
        for(int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if(cur->nexts[index] == nullptr) {
                return false;
            }
            cur = cur->nexts[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

