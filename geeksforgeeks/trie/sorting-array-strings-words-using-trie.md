**Problem**

Given an array of strings, print them in alphabetical (dictionary) order. If there are duplicates in input array, we need to print them only once.

Examples:

```
Input : "abc", "xy", "bcd"
Output : abc bcd xy         

Input : "geeks", "for", "geeks", "a", "portal", 
        "to", "learn", "can", "be", "computer", 
        "science", "zoom", "yup", "fire", "in", "data"
Output : a be can computer data fire for geeks
         in learn portal science to yup zoom
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
    void recurseTree(TrieNode *, string);
public:
    Trie();
    void insert(string);
    void printInSort();
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
        index = c - 'a';
        if(!temp->children[index]) {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
}

void Trie::recurseTree(TrieNode *node, string currWord) {
    if(node->isEndOfWord) {
        cout<<currWord<<" ";
    }
    string word;
    for(int i = 0; i<ALPHABET_SIZE; i++) {
        if(node->children[i]) {
            word = currWord + (char)(i+'a');
            recurseTree(node->children[i], word);
        }
    }
}

void Trie::printInSort() {
    string currWord = "";
    for(int i = 0; i<ALPHABET_SIZE; i++) {
        if(root->children[i]) {
            currWord = (char)(i + 'a');
            recurseTree(root->children[i], currWord);
        }
    }
    cout<<"\n";
}

int main() {
    vector<string> v = {"geeks", "for", "geeks", "a", "portal", "to", "learn", "can", "be", "computer", "science", "zoom", "yup", "fire", "in", "data"};
    Trie *trie = new Trie();
    for(string s: v) {
        trie->insert(s);
    }
    trie->printInSort();
}

```
