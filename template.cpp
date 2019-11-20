#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define REP(i, n) for (Int i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (Int i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj), rend(obj)
#define fi first
#define se second
using ii = pair<Int, Int>;
template <class T> inline bool chmax(T& a, const T& b) {
    if (a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T& a, const T& b) {
    if (a <= b) return false;
    a = b;
    return true;
}

template <class T> std::ostream& print(std::ostream& out, T const& val) { return (out << val << " "); }
template <class T1, class T2> std::ostream& print(std::ostream& out, std::pair<T1, T2> const& val) {
    return (out << "{" << val.first << " " << val.second << "} ");
}
template <template <class, class...> class TT, class... Args>
std::ostream& operator<<(std::ostream& out, TT<Args...> const& cont) {
    for (auto&& elem : cont) print(out, elem);
    return out;
}

#ifdef _MY_DEBUG
#define dump(...)                                                                                                    \
    cerr << "/* " << #__VA_ARGS__ << " [" << __LINE__ << ":" << __FUNCTION__ << "]" << endl, dump_func(__VA_ARGS__), \
        cerr << "*/\n\n";
#else
#define dump(...)
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) {
    cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...);
}

struct SetupIO {
    SetupIO() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }
} setup_io;
// ******************************************************************************************************************
// **************************************** TEMPLATE END ************************************************************
// ******************************************************************************************************************

signed main() {}
