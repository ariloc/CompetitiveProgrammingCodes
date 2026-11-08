#include <bits/stdc++.h>
#include <cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)c.size()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 1e6+5;

#define bint __int128
struct Hash {
    bint MOD = 212345678987654321LL,P=1777771,PI=106955741089659571LL;
    vector<bint> pot;
    bint hsh;
    vi func;
    
    Hash (int n) {
        assert((P*PI)%MOD==1);
        func.resize(n);
        iota(all(func),0);

        pot.resize(n);
        bint p=1;
        hsh = 0;
        forn(i,n){
            hsh = (hsh+p*func[i])%MOD;
            pot[i] = p;
            p=(p*P)%MOD;
        }
    }
    ll get(){ return (ll)hsh; }
    void swp(int i, int j) {
        int v1 = func[i], v2 = func[j];
        hsh = (hsh - (pot[i]*v1)%MOD + MOD)%MOD;
        hsh = (hsh - (pot[j]*v2)%MOD + MOD)%MOD;

        hsh = (hsh + pot[j]*v1)%MOD;
        hsh = (hsh + pot[i]*v2)%MOD;
        swap(func[i],func[j]);
    }
};

map<bint,int> pref;

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    Hash h(k);

    ll r = 0;
    pref[h.get()]++;
    forn(i,n) {
        int a,b; cin >> a >> b; --a, --b;
        h.swp(a,b);
        auto it = pref.find(h.get());
        if (it != pref.end()) {
            r += (*it).snd;
            //cerr << (*it).snd;
        }
        pref[h.get()]++;
    }

    cout << r << '\n';
   
    return 0;
}
