**Problem**

Given a string s, break s such that every substring of the partition can be found in the dictionary. Return the minimum break needed.
Examples:
```
Given a dictionary ["Cat", "Mat", "Ca", 
     "tM", "at", "C", "Dog", "og", "Do"]

Input :  Pattern "CatMat"
Output : 1 
Explanation: we can break the sentences
in three ways, as follows:
CatMat = [ Cat Mat ]  break 1
CatMat = [ Ca tM at ] break 2
CatMat = [ C at Mat ] break 2  so the 
         output is: 1

Input : Dogcat
Output : 1
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
public:
    Trie();
    void insert(string);
    void minWordBreak(string, int, int, int &);
};

Trie::Trie() {
    root = getNode();
}

TrieNode *Trie::getNode() {
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

void Trie::minWordBreak(string s, int start, int level, int &minBreak) {
    if(start == s.size()) {
        minBreak = min(minBreak, level-1);
        return;
    }
    TrieNode *temp = root;
    int index;
    for(int i = start; i<s.length(); i++) {
        index = tolower(s[i]) - 'a';
        if(!temp->children[index]) {
            return;
        }
        if(temp->children[index]->isEndOfWord) {
            minWordBreak(s, i+1, level+1, minBreak);
        }
        temp = temp->children[index];
    }
}


int main() {
    vector<string> v = {"Cat", "Mat", "Ca", "Ma", "at", "C", "Dog", "og", "Do"};
    Trie *trie = new Trie();
    for(string s: v) {
        trie->insert(s);
    }
    int minBreak = INT_MAX;
    trie->minWordBreak("CatMatat", 0, 0, minBreak);
    cout<<minBreak<<'\n';
}

```
