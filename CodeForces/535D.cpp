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

const int MAXN = 1e6+5;
const int MOD = 1e9+7;
const int MAXA = 26;

vi KMPcompute (string s) { // saco los bordes, prefijos que son sufijos
    int N = (int)s.size();
    vi KMP(N,0);
    forsn(i,1,N) {
        int j = KMP[i-1];
        while (j and s[i] != s[j])
            j = KMP[j-1];
        if (s[i] == s[j]) j++;
        KMP[i] = j;
    }
    return KMP;
}

int binMod (int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

int arr[MAXN];
bitset<MAXN> done;
string lookup;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    string p; cin >> p;
    forn(i,m) cin >> arr[i], arr[i]--;

    lookup = string(n,'?');
    int act = 0, actCpy = -1, ind = 0;
    forn(i,n) {
        if (arr[act] == i) actCpy = act, ind = 0, act++;
        if (actCpy >= 0 && actCpy < m && ind < (int)p.size())
            lookup[i] = p[ind++];
    }

    lookup = (p+'$'+lookup);

    // saquemos las apariciones en la string
    vi aux = KMPcompute(lookup), aparic;
    forsn(i,(int)p.size()+1,aux.size())
        if (aux[i] == (int)p.size())
            aparic.pb(i-2*(int)p.size());

    bool posib = 1;
    forn(i,m) { // si funcionó todo bien, debería de encontrarlos todos
        auto it = lower_bound(all(aparic),arr[i]);
        if (it == aparic.end() || (*it) != arr[i])
            posib = 0;
    }

    if (!posib) return cout << 0, 0;

    int cnt = 0;
    forsn(i,(int)p.size()+1,lookup.size())
        cnt += (lookup[i] == '?');

    cout << binMod(MAXA,cnt);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!