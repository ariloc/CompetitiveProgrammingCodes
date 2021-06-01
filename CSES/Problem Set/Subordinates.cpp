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
 
const int MAXN = 2e5+5;
 
vi G[MAXN];
int child[MAXN];
 
int dfs (int st) {
    int sum = 0;
    for (auto &i : G[st])
        sum += dfs(i);
    child[st] = sum;
    return sum+1;
}
 
int main() {
    FAST_IO;
 
    int n; cin >> n;
    forn(i,n-1) {
        int x; cin >> x; x--;
        G[x].pb(i+1);
    }
 
    dfs(0);
    forn(i,n) cout << child[i] << ' ';
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!