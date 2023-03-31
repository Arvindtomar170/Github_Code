#include<bits/stdc++.h>
using namespace std;
//comparator using class by overaloading () operator
// class cmprator{
//     public:
//     bool operator()(int a,int b){
//         return a>b;
//     }
// };
        //syntex --> set<int,cmparator>set_name, map<int,int,cmprator>map_name;

//comparator using lamda functions
auto cmp=[&](int a,int b){return a>b;};
        //syntex ---> set<int,decltype(cmp)>set_name(cmp),map<int,int,decltype(cmp)>set_name(cmp)


// using function  of return type boolean
// bool cmp(int a,int b){
//     return a>b;
// }
        //syntex ----> set<int,decltype(cmp)*>set_name(cmp), map<int,int,decltype(&cmp)>set_name(cmp) ,priority_queue<int,vector<int>,decltype(&cmp)>p(cmp);


int main(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);int test=1;
        priority_queue<int,vector<int>,decltype(cmp)>p(cmp);
        for(int i=0;i<5;i++){
            p.push(i);
        }
        while(!p.empty()){
            cout<<p.top()<<endl;
            p.pop();
        }
    }