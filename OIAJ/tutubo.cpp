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

int const K = 60;
int const MAXN = 1e5+5;

int S[K][MAXN];

vector<int> tutubo(vector<int> &siguiente, vector<int> &preguntaX, vector<long long> &preguntaK) {
    int n = sz(siguiente);
    forn(i,n) S[0][i] = siguiente[i];
    forsn(k,1,K) forn(i,n) S[k][i] = S[k-1][S[k-1][i]];

    vi rta;
    forn(i,sz(preguntaX)) {
        ll k = preguntaK[i];
        int x = preguntaX[i];
        forn(l,K) if (k&(1LL<<l)) x = S[l][x];
        rta.pb(x);
    }
    return rta;
}
