#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define PI acos(-1)
#define EULER 2.7182818284
#define endl '\n'

void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
}

//////////////////////////////////////////////////////////////////////

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

int main() {
    setIO();
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<vector<int> > v(n, vector<int>(n));
        if(n % 2) {
            int val = 1;
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    v[i][j] = val++;
                }
            }
        } else {
            int val = 1;
            for(int i = 0; i<n; i++) {
                if(i % 2) {
                    for(int j = (n-1); j>=0; j--) {
                        v[i][j] = val++;
                    }
                } else {
                    for(int j = 0; j<n; j++) {
                        v[i][j] = val++;
                    }
                }
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
