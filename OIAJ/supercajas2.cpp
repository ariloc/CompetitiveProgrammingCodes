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

int const INF = 2e9+5;

map<vi,int> cnt;

int supercajas(int N, int X, int Y, int Z, vector<int> &a, vector<int> &b, vector<int> &c) {
    int m = sz(a);
    forn(i,m) {
        vi d = {a[i],b[i],c[i]};
        sort(all(d));
        cnt[d]++;
    }

    vi d = {X,Y,Z};
    sort(all(d));
    int prod = X*Y*Z;
    int mini = INF;
    for (auto &i : cnt) {
        if (i.snd >= N && d[0] <= i.fst[0] && d[1] <= i.fst[1] && d[2] <= i.fst[2]) {
            mini = min(mini, i.fst[0]*i.fst[1]*i.fst[2] - prod);
        }
    }
    
    return mini == INF ? -1 : mini;
}
