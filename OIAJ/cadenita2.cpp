#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 505;
int const INF = 2e9;

int win[MAXN][MAXN];
int n,k;

vector<int> cadenita2(vector<vector<int>> &votos) {
    n = sz(votos);
    k = sz(votos[0]);
    forn(i,n) forn(j,k) forsn(j2,j+1,k) win[votos[i][j]-1][votos[i][j2]-1]++;

    vi ord(k);
    iota(all(ord),1);

    forn(_,k+2) {
        forn(i,k-1) if (win[ord[i]-1][ord[i+1]-1] < win[ord[i+1]-1][ord[i]-1]) swap(ord[i],ord[i+1]);
    }

    return ord;
}
