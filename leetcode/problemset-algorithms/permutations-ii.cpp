#include<bits/stdc++.h>
using namespace std;

/////////////////////////////// DEBUG ////////////////////////////////

vector<string> split(const string &s, char c)
{
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        v.emplace_back(x);
    return move(v);
}

class Debugger
{
public:
    Debugger(const std::string &_separator = ", ") : first(true), separator(_separator) {}
    template <typename ObjectType>
    Debugger &operator,(const ObjectType &v)
    {
        if (!first)
            std::cerr << separator;
        std::cerr << v;
        first = false;
        return *this;
    }
    ~Debugger() { std::cerr << "; "; }

private:
    bool first;
    std::string separator;
};

template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    bool first = true;
    os << "[";
    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::set<T> &v)
{
    bool first = true;
    os << "[";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::queue<T> &v)
{
    bool first = true;
    std::queue<T> temp = v;
    T tempvar;
    os << "[";
    while (!temp.empty())
    {
        tempvar = temp.front();
        temp.pop();
        if (!first)
            os << ", ";
        os << tempvar;
        first = false;
    }
    return os << "]";
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const std::priority_queue<T> &v)
{
    bool first = true;
    std::priority_queue<T> temp = v;
    T tempvar;
    os << "[";
    while (!temp.empty())
    {
        tempvar = temp.top();
        temp.pop();
        if (!first)
            os << ", ";
        os << tempvar;
        first = false;
    }
    return os << "]";
}

template <typename T1, typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::map<T1, T2> &v)
{
    bool first = true;
    os << "[";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if (!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}

#define debugUtil(args...) (Debugger()), args
#define debug(args...)                            \
    {                                             \
        __line_num(__LINE__);                     \
        __evars(split(#args, ',').begin(), args); \
    }

inline void __line_num(int line)
{
    std::cerr << "#" << line << ": ";
}
inline void __evars(vector<string>::iterator it) { cerr << endl; }

template <typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args)
{
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    debugUtil(a);
    __evars(++it, args...);
}

//////////////////////////////////////////////////////////////////////

void fillComplete(vector<vector<int> > &ans, vector<int> &currAns, int currPos, int n, vector<bool> &
visited, vector<int> &nums) {
    if(currPos == n) {
        ans.push_back(currAns);
    }
    for(int i = 0; i<n; i++) {
        if(!visited[i] && ((i == 0) || visited[i-1] || (nums[i] != nums[i-1]))) {
            currAns[currPos] = nums[i];
            visited[i] = true;
            fillComplete(ans, currAns, currPos+1, n, visited, nums);
            visited[i] = false;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<bool> visited(n, false);
    vector<vector<int> > ans;
    vector<int> currAns(n);
    fillComplete(ans, currAns, 0, n, visited, nums);
    return ans;
}

int main() {
    vector<int> v = {1, 1, 2};
    vector<vector<int> > ans = permuteUnique(v);
    for(auto ee: ans) {
        for(auto e: ee) cout<<e<<" ";
        cout<<"\n";
    }
}
