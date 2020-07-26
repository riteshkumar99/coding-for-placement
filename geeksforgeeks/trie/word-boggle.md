**Problem**

Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:
```
Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ
```

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer x denoting the no of words in the dictionary. Then in the next line are x space separated strings denoting the contents of the dictinory. In the next line are two integers N and M denoting the size of the boggle. The last line of each test case contains NxM space separated values of the boggle.

Output:
For each test case in a new line print the space separated sorted distinct words of the dictionary which could be formed from the boggle. If no word can be formed print -1.

Constraints:
1<=T<=10
1<=x<=10
1<=n,m<=7

Example:
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ

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
    int n, m, maxLen;
    vector<short> offset = {-1, 0, 1};
    bool isInside(int, int);
    TrieNode *getNode();
    void searchWord(vector<vector<char> > &, int, int, TrieNode*, vector<vector<bool> > &, string, set<string> &);
public:
    Trie();
    void insert(string);
    void solveWordBoggle(vector<vector<char> > &);
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
    maxLen = max(maxLen, (int)s.length());
    for(char c: s) {
        index = tolower(c) - 'a';
        if(!temp->children[index]) {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
}

bool Trie::isInside(int x, int y) {
    return (0 <= x and x < n) and (0 <= y and y < m);
}

void Trie::searchWord(vector<vector<char> > &v, int x, int y, TrieNode *node, vector<vector<bool> > &visited, string currWord, set<string> &ans) {
    currWord += v[x][y];
    if(node->isEndOfWord) {
        ans.insert(currWord);
    }
    if(currWord.length() > maxLen) {
        return;
    }
    int index;
    for(short xOffset: offset) {
        for(short yOffset: offset) {
            if(isInside(x+xOffset, y+yOffset) and !visited[x+xOffset][y+yOffset]) {
                index = tolower(v[x+xOffset][y+yOffset]) - 'a';
                if(node->children[index]) {
                    visited[x+xOffset][y+yOffset] = true;
                    searchWord(v, x+xOffset, y+yOffset, node->children[index], visited, currWord, ans);
                    visited[x+xOffset][y+yOffset] = false;
                }
            }
        }
    }
}

void Trie::solveWordBoggle(vector<vector<char> > &v) {
    n = v.size(), m = v[0].size();
    int index;
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    set<string> ans;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            index = tolower(v[i][j]) - 'a';
            if(root->children[index]) {
                visited[i][j] = true;
                searchWord(v, i, j, root->children[index], visited, "", ans);
                visited[i][j] = false;
            }
        }
    }
    if(ans.size() == 0) {
        cout<<-1<<"\n";
    } else {
        for(string s: ans) {
            cout<<s<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    int t, x, n, m;
    string s;
    cin>>t;
    while(t--) {
        cin>>x;
        Trie *trie = new Trie();
        for(int i = 0; i<x; i++) {
            cin>>s;
            trie->insert(s);
        }
        cin>>n>>m;
        vector<vector<char> > boggle(n, vector<char>(m));
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                cin>>boggle[i][j];
        trie->solveWordBoggle(boggle);
    }
}

```
