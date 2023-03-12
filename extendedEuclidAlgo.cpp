#include<bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;
struct triplet
{
    int __gcd=0;
    int coff1=0;
    int coff2=0;
};

/* 
    a*x +b*y = __gcd
    __gcd(a,b) =  __gcd(b,a%b) = b*coff1+ [a-(a/b)*b]*coff2 =  b*(coff1-(a/b)*coff2)+a*coff2
    ax + by = bx1 + (a%b)*y1  =  a*y1 + b( x1-(a/b)*y1 )  =>  x=y1  and y= x1-(a/b)*y1
*/
triplet extendedEuclid(int a,int b){
    triplet ans;
    if(b==0){
        ans.__gcd=a;
        ans.coff1=1;
        ans.coff2=0;    //a*x+0=__gcd   
        return ans;
    }
    triplet smallans=extendedEuclid(b,a%b);

    ans.__gcd=smallans.__gcd;
    ans.coff1=smallans.coff2;
    ans.coff2=smallans.coff1-(a/b)*smallans.coff2;
    return ans;
}

int main(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);int test=1;
        triplet ans = extendedEuclid(35,15);
        cout<<ans.__gcd<<" "<<ans.coff1<<" "<<ans.coff2<<endl;
        return 0;
    }