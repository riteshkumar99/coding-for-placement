**Problem**

```
During delete operation we delete the key in bottom up manner using recursion. The following are possible conditions when deleting key from trie,

    Key may not be there in trie. Delete operation should not modify trie.
    Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another key in trie). Delete all the nodes.
    Key is prefix key of another long key in trie. Unmark the leaf node.
    Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf node of longest prefix key.
```

**Solution**

```cpp
#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    array<TrieNode *, ALPHABET_SIZE> children;
    bool isEndOfWord;
};

class Trie {
    TrieNode *root;
    TrieNode *getNode();
    TrieNode *removeUtil(TrieNode *, string, int);
    bool isEmptyUtil(TrieNode *);
public:
    Trie();
    void insert(string);
    bool search(string);
    bool isEmpty() { return isEmptyUtil(root); }
    void remove(string s) { removeUtil(root, s, 0); }
};

Trie::Trie() {
    root = getNode();
}

TrieNode* Trie::getNode() {
    TrieNode *node = new TrieNode;
    node->isEndOfWord = false;
    for(TrieNode* &i: node->children) {
        i = nullptr;
    }
    return node;
}

void Trie::insert(string s) {
    TrieNode *temp = root;
    int index;
    for(char c: s) {
        index = tolower(c) - 'a';
        if(!temp->children[index]) {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
}

bool Trie::search(string s) {
    TrieNode *temp = root;
    int index;
    for(char c: s) {
        index = tolower(c) - 'a';
        if(!temp->children[index]) {
            return false;
        }
        temp = temp->children[index];
    }
    return (temp != nullptr and temp->isEndOfWord);
}

bool Trie::isEmptyUtil(TrieNode *node) {
    for(TrieNode *i: node->children) {
        if(i != nullptr) {
            return false;
        }
    }
    return true;
}

TrieNode* Trie::removeUtil(TrieNode *node, string s, int depth) {
    if(node == nullptr) {
        return nullptr;
    }
    if(depth == s.length()) {
        if(node->isEndOfWord) {
            node->isEndOfWord = false;
        }
        if(isEmptyUtil(node)) {
            delete node;
            node = nullptr;
        }
        return node;
    }
    int index = tolower(s[depth]) - 'a';
    node->children[index] = removeUtil(node->children[index], s, depth+1);
    if(isEmptyUtil(node) and !node->isEndOfWord) {
        delete node;
        node = nullptr;
    }
    return node;
}

int main() {
    vector<string> v = {"the", "a", "there", 
                      "answer", "any", "by", 
                      "bye", "their", "hero", "heroplane"};
    Trie *trie = new Trie();
    for(string i: v) {
        trie->insert(i);
    }
    trie->search("the") ? cout << "Yes\n" : cout << "No\n";
    trie->search("these") ? cout << "Yes\n" : cout << "No\n";
    trie->remove("heroplane");
    trie->search("heroplane") ? cout << "Yes\n" : cout << "No\n";
    trie->search("hero") ? cout << "Yes\n" : cout << "No\n";
}

```
