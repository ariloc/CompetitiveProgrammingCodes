#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
 
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
 
const int MAXD = 1e6+5;
const int MAXN = 2e5+5;
 
int done[MAXD],mark[MAXD];
 
int main() {
    FAST_IO;
 
    int n; cin >> n;
    forn(i,n) {
        int x; cin >> x;
        done[x]++;
    }
 
    // criba
    for (int i = 2; i <= MAXD; i++)
        for(int j = i; j <= MAXD; j+=i)
            mark[i] += done[j];
 
    int maxi = 1;
    forn(i,MAXD) if (mark[i] > 1) maxi = max(maxi,i);
 
    cout << maxi;
 
    return 0;
}
 
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!