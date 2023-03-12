
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll N = 2e5;  // limit for array size
ll n;  // array size
ll t[2 * N];

void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] =min(t[i<<1] ,t[i<<1|1]);
}

void modify(ll p, ll value) {  // set value at position p
  for (t[p+=n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}


ll query(ll l, ll r) {  // sum on llerval [l, r)
  ll res = INT_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res= min(res, t[l++]);
    if (r&1) res =min(res, t[--r]);
  }
  return res;
}

int main() {
  ll q;
  cin>>n>>q;
  for (ll i = 0; i < n; ++i)cin>>t[n+i];
  build();
  for(ll i=0;i<q;i++){
    ll a,b;cin>>a>>b;
    cout<<query(a-1,b)<<endl;
  }
  return 0;
}