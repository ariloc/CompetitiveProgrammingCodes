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

int const MAXN = 2005;

int pos[MAXN][MAXN];

vector<int> cadenita3(vector<vector<int>> &votos) {
    int n = sz(votos), k = sz(votos[0]);

    forn(i,n) forn(j,k) pos[i][votos[i][j]-1] = j;

    vi cad(k);
    iota(all(cad),1);
    int flo = n/2;
    sort(all(cad),[&](const int &lhs, const int &rhs){
        int cnt = 0;
        forn(i,n) cnt += pos[i][lhs-1] < pos[i][rhs-1];
        return cnt > flo;
    });

    return cad;
}
