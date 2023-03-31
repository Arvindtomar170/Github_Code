#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

/* ----------------------- for using PBDS(policy base data structure) -------------------*/
       //#include<ext/pb_ds/assoc_container.hpp>
       //#include<ext/pb_ds/tree_policy.hpp>
       //using namespace __gnu_pbds;
       //typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key (0 based indexing)
/*----------------------------------------------------------------------------------------*/

class Fenwick{                                /*1-indexed*/
    int N;
    int* MyTree;   //vector<int>MyTree
public:
    Fenwick(int a[],int N){                   /*constructor to initialize Fenwick Tree*/
        this->N=N;
        this->MyTree=new int[(this->N)+1];
        for(int i=0;i<=N;i++){
            MyTree[i]=0;
        }
        for(int i=1;i<=N;i++){
            addValue(i,a[i-1]);
        }
    }
    int GetSum(int i){                         /*get i-th Prefix Sum*/
        int ix=i;
        int sum=0;
        while(ix>0){
            sum+=MyTree[ix];
            ix=ix-(ix&-ix);
        }
        return sum;
    }
    void addValue(int i,int v){                 /*add v to i-th value*/
        int ix=i;
        while(ix<=N){
            MyTree[ix]+=v;
            ix=ix+(ix&-ix);
        }
    }
    int get(int i){
        return GetSum(i)-GetSum(i-1);           /*get i-th value of array*/
    }
    int RangeSum(int l,int r){                  /*getting sum from i-th value to r-th val*/
        return GetSum(r)-GetSum(l-1);
    }

    /*
    Important -->
    How to remove all the bits from a number except last significant bit 
            Answer :
                if the number  is x:--> x=x&-x;
    How to find responsiblity of a no:
	X is in a form of =  a1b
			    X'= a'0b'
			 x'+1 = a'1b
	know  X&(X'+1)=000..0.1b(b=00..0)
	x'+1=-x  -->basic knowladge😊
    */
};

int32_t main(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int a[]={1,2,3,4,5,6,7,8};
        Fenwick obj(a,8);
        cout<<obj.GetSum(4)<<endl;
        obj.addValue(1,11);
        cout<<obj.GetSum(4)<<endl;

        for(int i=0;i<8;i++)
            cout<<obj.get(i+1)<<" ";
        return 0;
    }