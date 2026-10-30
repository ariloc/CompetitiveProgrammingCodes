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

int sanar(int magia, vector<int> &vidaInicial, vector<int> &vidaActual, vector<int> &distancia) {
    vi near,far;
    forn(i,sz(distancia)) {
        auto go = [](vi &vec, int v) {
            while (v > 0)
                vec.pb(min(10,v)), v -= 10;
        };
        if (distancia[i] == 1)
            go(near,vidaInicial[i]-vidaActual[i]);
        else
            go(far,vidaInicial[i]-vidaActual[i]);
    }

    sort(all(near));
    sort(all(far));
    
    int r = 0;
    forn(i,magia/3+1) {
        int s = 0;
        forn(j,min(sz(near),i)) s += near[sz(near)-j-1];
        int auxmagia = magia - 3*i;
        dforn(j,sz(far)) if (auxmagia >= 5) s += far[j], auxmagia -= 5;
        r = max(r,s);
    }

    return r;
}
