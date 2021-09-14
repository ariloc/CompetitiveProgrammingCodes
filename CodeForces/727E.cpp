#include <bits/stdc++.h>
    
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
    
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
    
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int P = 31, PP = 53;
const int MOD = 1e9+93;
const int INV_MOD = 935483958;
const int INV_MOD2 = 132075484;
const int MAXN = 2e6+5;

ll hashes1[MAXN], hashes2[MAXN];
map<pair<ll,ll>,vi> hashSet;
vector<string> games;
set<int> foundIds;
vi orden;
int found[MAXN];
int n,k,sz;

ll hashIt (const string &s, int p, int m) {
    ll r = 0, potP = 1;
    for (auto &i : s) {
        r = (r + (i-'a'+1) * potP) % m;
        potP = (potP * p) % m;
    }
    return r;
}

void hashArray (int i_m, int m, int p, ll arr[], const string &s) {
    string aux;
    forn(i,k) aux.pb(s[i]);
    ll act_hash = hashIt(aux,p,m);

    ll lastPotP = 1;
    forn(i,k-1) lastPotP = (lastPotP * p)%m;

    arr[0] = act_hash;
    for (int i = k; i-k+1 < sz; i++) {
        act_hash = (act_hash - (s[i-k] - 'a' + 1) + m)%m;
        act_hash = (act_hash * i_m)%m;
        act_hash = (act_hash + (s[i] - 'a' + 1) * lastPotP)%m;
        arr[i-k+1] = act_hash;
    }
}

int main() {
    FAST_IO;

    cin >> n >> k;
    string s; cin >> s;
    s += s; // lo duplico por conveniencia
    sz = n*k;

    hashArray(INV_MOD,MOD,P,hashes1,s);
    hashArray(INV_MOD2,MOD,PP,hashes2,s);

    forn(i,sz) hashSet[{hashes1[i],hashes2[i]}].pb(i);

    int g; cin >> g;
    forn(i,g) {
        string x; cin >> x;
        games.pb(x);

        ll mHash = hashIt(x,P,MOD), mHash2 = hashIt(x,PP,MOD);

        pair<ll,ll> auxPair = {mHash,mHash2};
        auto it = hashSet.find(auxPair);
        if (it != hashSet.end()) {
            for (auto &j : (*it).snd)
                found[j] = i+1; // así 0 es que no encontré nada
        }
    }

    forn(i,k) {
        foundIds.clear(), orden.clear();
        bool posib = true;
        
        for (int j = i; j < sz; j += k) {
            if (!foundIds.count(found[j]) && found[j]) 
                foundIds.insert(found[j]), orden.pb(found[j]);
            else posib = false;
        }

        if (posib) {
            cout << "YES\n";
            for (auto &j : orden) cout << j << ' ';
            return 0;
        }
    }

    cout << "NO";

    return 0;
}