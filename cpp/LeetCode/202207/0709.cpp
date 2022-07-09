#include "../helper.h"

struct TrieNode {
    bool isWord;
    map<char, TrieNode> children;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    void insert(string word) {
        TrieNode *node = &root;
        for (auto ch: word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children.insert({ch, {}});
            }
            node = &node->children[ch];
        }
        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = &root;
        for (auto ch: word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children.insert({ch, {}});
            }
            node = &node->children[ch];
        }
        return node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = &root;
        for (auto ch: prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = &node->children[ch];
        }
        return true;
    }

    TrieNode root;
};

TEST(TrieTest, case1) {
    Trie trie;
    trie.insert("hello");
    EXPECT_FALSE(trie.search("hell"));
    EXPECT_FALSE(trie.search("helloa"));
    EXPECT_TRUE(trie.search("hello"));
    EXPECT_TRUE(trie.startsWith("hell"));
    EXPECT_TRUE(trie.startsWith("helloa"));
    EXPECT_TRUE(trie.startsWith("hello"));
}

