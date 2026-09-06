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

int const MAXN = 5;
int const X[] = {0,1,0,-1};
int const Y[] = {1,0,-1,0};

bitset<MAXN> done[MAXN];

string plastetris(vector<string> cajita) {
    int seen = 0;
    forn(i,4) forn(j,4) if (!done[i][j] && cajita[i][j] == 'X') {
        ++seen;

        queue<ii> Q;
        Q.push({i,j});
        int cnt = 0;
        done[i][j] = true;
        while (!Q.empty()) {
            auto e = Q.front(); Q.pop();
            
            ++cnt;

            forn(k,4) {
                int ti = e.fst + X[k], tj = e.snd + Y[k];
                if (ti < 0 || tj < 0 || ti >= 4 || tj >= 4) continue;
                if (cajita[ti][tj] != 'X') continue;
                if (done[ti][tj]) continue;
                done[ti][tj] = true;
                Q.push({ti,tj});
            }
        }

        if (cnt != 4) return "NO";
    }
    return (seen == 1 ? "SI" : "NO");
}
