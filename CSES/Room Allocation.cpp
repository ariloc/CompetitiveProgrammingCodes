#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;

int room[MAXN];
ii t[2*MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) {
        int a,b; scanf("%d %d",&a,&b);
        t[2*i] = {a,i+1}; t[2*i+1] = {b+1,-(i+1)};
        // como tienen negativos, todas las liberadas las agrego primero
    }

    sort(t,t+n+n);

    priority_queue<int, vi, greater<int>> occup;
    forn(i,n) occup.push(i+1);
    int maxi = 1;
    forn(i,2*n) {
        maxi = max(maxi,n-(int)occup.size());
        if (t[i].snd > 0) {room[t[i].snd] = occup.top(); occup.pop();}
        else occup.push(room[abs(t[i].snd)]);
    }

    printf("%d\n",maxi);
    forsn(i,1,n+1) printf("%d ",room[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
