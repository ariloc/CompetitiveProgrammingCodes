#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;int P[200005][19],n,q,x,k;
int main(){
    cin>>n>>q;
    forn(i,n-1)cin>>P[i+2][0];
    forn(i,19)if(i)forn(j,n)P[j+1][i]=P[P[j+1][i-1]][i-1];
    forn(i,q){
        cin>>x>>k;
        forn(i,19)if(k&(1<<i))x=P[x][i];
        cout<<(x?x:-1)<<'\n';
    }
}
