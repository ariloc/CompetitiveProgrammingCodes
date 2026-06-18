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

vector<pair<int,ii>> rut;
map<int,int> art;

long long genio(int N, int M, vector<int> f, vector<int> c) {
    int a = (int)f.size();

    forn(i,a) {
        auto it = art.find(c[i]);
        if (it != art.end()) (*it).snd = min((*it).snd, f[i]);
        else art[c[i]] = f[i];
    }

    vi toadd;
    for (auto &e : art) if (e.fst-1 >= 1 && art.find(e.fst-1) == art.end()) toadd.pb(e.fst-1);
    if (art.find(M) == art.end()) toadd.pb(M);
    for (auto &i : toadd) art[i] = N+1;

    vector<ii> artlst;
    for (auto &e : art) artlst.pb(e);

    rut.pb({0,{0,1}});

    ll acc = 0, maxi = 0;
    forn(i,artlst.size()) {
        ii e = artlst[i];
        if (e.snd == 1) break;
        while (!rut.empty() && rut.back().fst >= e.snd) {
            acc -= rut.back().fst * (ll)rut.back().snd.snd;
            rut.pop_back();
        }

        int lstpos = rut.back().snd.fst + rut.back().snd.snd;
        int dist = e.fst - lstpos + 1;
        acc += dist * (ll)(e.snd-1);
        maxi = max(maxi,acc);
        rut.pb({e.snd-1,{lstpos,dist}});
    }

    return maxi;
}
