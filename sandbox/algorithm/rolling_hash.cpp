#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template<typename S, typename T> S amax(S &a, const T &b) { if(b > a) a = b; return a; }
template<typename S, typename T> S amin(S &a, const T &b) { if(b < a) a = b; return a; }

#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define pb emplace_back
#define sz(x) (int) (x).size()
#define ln '\n'
using ll = long long;
using pi = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
const ll INF = 2e9;
const int N = 1e5 + 3;

const int P = 239017, mod = 1e9 + 7;

ll p[N], h[N];
inline ll get(int l, int r) { return (h[r] - (h[l] * p[r - l])%mod + mod)%mod; }


void runcase() {
    string s; cin >> s;
    int n = sz(s);
    p[0] = 1;
    for(int i=0; i<n-1; ++i){
        h[i + 1] = h[i] * P + s[i], p[i + 1] = p[i] * P;
    }


    return ;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int TC = 1;
    // cin >> TC; 
    while(TC--) runcase();
    return 0;
}