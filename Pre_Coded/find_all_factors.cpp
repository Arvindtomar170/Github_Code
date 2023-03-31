#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



// find all factors of a number in nlog(n);  -> n+ n/2+ n/3+n/4+ n/5 +.......=n*(1+ 1/2 + 1/3 +1/4 + 1/5 + ...)
vector<ll> factor[100001];
void init(){
    for(ll i=1;i<100001;i++){
        for(ll j=i;j<=100001;j+=i){
                factor[j].push_back(i);
        }
    }
}

int main(){
        init();
        for(auto i:factor[25]){
            cout<<i<<" ";
        }
        cout<<endl;
        return 0;
    }