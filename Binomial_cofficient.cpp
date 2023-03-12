#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const mod=1e9+7;
ll const N=1e6+1;
vector<ll>F(N+5);
ll P(ll b,ll e=mod-2){
    ll res=1;
    while(e>0){
        if(e&1)
            res=(res*b)%mod;
        b=(b*b)%mod;
        e=e/2;
    }
    return (res+mod)%mod;
}
ll nCr(ll n,ll r){
        F[0]=1;
        for(ll i=1;i<N+2;i++)
            F[i]=(F[i-1]*i)%mod;
        return ((( F[n]*P(F[n-r]))%mod)*P(F[r]))%mod;
}

int32_t main(){
        cout<<nCr(5,2);
        return 0;
    }
