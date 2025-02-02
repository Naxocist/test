#include "sum_product.h"
#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;
const int N = 1e5 + 3, mod=1e9+7;
ll fac[N], inv[N];
vector<int> v;

ll binpow(ll x, ll y) {
    ll res = 1;
    for(;y;y>>=1, x*=x,x%=mod){
        if(y&1)res*=x;
        res%=mod;
    }
    return res;
}

ll C(int n, int r) {
    return ((fac[n]*inv[n-r])%mod*inv[r])%mod;
}

ll res = 0;
int n;



int sum_product(int n, std::vector<int> a){
    v=a; ::n=n;
    for(int i=0; i<1<<(n-1); ++i){
        // 0=+,1=*
        stack<ll> st; st.push(a[0]);
        for(int j=0; j<n-1; ++j) {
            if(i&(1<<j)) {
                ll t = st.top(); st.pop();
                st.push((t*a[j+1])%mod);
            }else st.push(a[j+1]); 
        }

        ll s = 0;
        while(st.size()) {
            // cout << st.top() << endl;
            s += st.top(), s%=mod, st.pop();
        }
        // cout << s << endl;
        // div()
        res+=s,res%=mod;
    }
    // fac[0]=inv[0]=1;
    // for(int i=1; i<N; ++i) {
    //     fac[i]=i*fac[i-1],fac[i]%=mod;
    //     inv[i]=binpow(fac[i],mod-2);
    // }
    // int m = n-1;
    // ll res = 0;
    // for(int i=0; i<=m; ++i) {
    //     ll how = C(m, i);
    //     res += (how*(m-i+1))%mod;
    //     res%=mod;
    // }
    return res;
}
