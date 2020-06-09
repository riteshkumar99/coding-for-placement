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

int numSubarraysWithSum(vector<int>& a, int s) {
    int n = a.size(), num1 = accumulate(a.begin(), a.end(), 0), l = 0, leftCount, rightCount, count = 0;
    if(num1 < s) {
        return count;
    }
    vector<int> onePos(num1);
    for(int i = 0, j = 0; i<n; i++) {
        if(a[i]) {
            onePos[j++] = i;
        }
    }
    debug(onePos);
    while(l + s <= num1) {
        if(l == 0) {
            leftCount = onePos[l] + 1;
        } else {
            leftCount = onePos[l] - onePos[l-1];
        }
        if(l + s == num1) {
            rightCount = n - onePos[l+s-1];
        } else {
            rightCount = onePos[l+s] - onePos[l+s-1];
        }
        debug(leftCount, rightCount);
        count += leftCount*rightCount;
        l++;
    }
    return count;
}

int main() {
    vector<int> v = {0, 0, 1, 0, 0};
    cout<<numSubarraysWithSum(v, 2)<<"\n";
}
