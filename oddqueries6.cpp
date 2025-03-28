#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll M=1e9+7;
const int N=1e6;
vector<ll>prefix_sum(N+1,0);
// for(int ele=1;ele<=N;++ele){
//     prefix_sum[ele]=ele+prefix_sum[ele-1];
// }
void find_sum(vector<ll>&vec1,int size){
    for(int ele=0;ele<size;++ele){
        if(ele==0){
            prefix_sum[ele+1]=vec1[ele];
        }
        else{
        prefix_sum[ele+1]=vec1[ele]+prefix_sum[ele];
    }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll>vec(n);
        for(int i=0;i<n;++i){
            cin>>vec[i];
        }
        find_sum(vec,n);
        for(int i=1;i<=q;++i){
            ll l,r,k;
            cin>>l>>r>>k;
            ll sum=prefix_sum[n]+((r-l+1)*k)+prefix_sum[l-1]-prefix_sum[r];
            if(sum%2==0){
                cout<<"NO"<<"\n";
            }
            else{
                cout<<"YES""\n";
            }
        }
    }
    return 0;
}