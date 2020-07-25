**Problem**

Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use the TRIE data structure and search the given string A. If found print 1 else 0.

Expected Time Complexity: O(N * WORD_LEN + A_LEN).
Expected Auxiliary Space: O(N * WORD_LEN).

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of a integer N, denoting the number of element in a Trie to be stored.
Second line of each test case consists of N space separated strings denoting the elements to be stored in the trie.
Third line of each test case consists of a String A to be searched in the stored elements.

Output:
Print the respective output in the respective line.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
1
8
the a there answer any by bye their
the
Output:
1

**Solution**

```cpp
#include <bits/stdc++.h>
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
    bool search(string);
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

bool Trie::search(string s) {
    TrieNode *temp = root;
    int index;
    for(char c: s) {
        index = c - 'a';
        if(!temp->children[index]) {
            return false;
        }
        temp = temp->children[index];
    }
    return (temp != nullptr and temp->isEndOfWord);
}

int main() {
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        Trie *trie = new Trie();
        string s;
        for(int i = 0; i<n; i++) {
            cin>>s;
            trie->insert(s);
        }
        cin>>s;
        cout<<trie->search(s)<<"\n";
    }
	return 0;
}
```
