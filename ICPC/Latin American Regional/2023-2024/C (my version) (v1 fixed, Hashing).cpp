#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 4e5+5;
ll const MOD = 2163796854027819461LL;
int const P = 999961;

int arr[MAXN];
map<ll,int> prefs;
int histo[MAXN];
ll potp[MAXN],sumpot[MAXN];
set<ii> posic;

void updhash (ll &x, int n, int pos, int delta) {
    int e = n-pos-1;
    x = ((x + (delta * (__int128)potp[e])%MOD)%MOD + MOD)%MOD;
}

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) cin >> arr[i];

    potp[0] = 1, sumpot[0] = 1;
    forsn(i,1,MAXN) potp[i] = (potp[i-1] * (__int128)P)%MOD;
    forsn(i,1,MAXN) sumpot[i] = (sumpot[i-1] + potp[i])%MOD;

    forn(i,k) posic.insert({0,i});

    prefs[0] = 0;

    ll curhsh = 0, rsthash = 0;
    int rta = 0;
    forn(i,n) {
        int prvmini = (*(posic.begin())).fst;
        posic.erase({histo[arr[i]-1],arr[i]-1});
        histo[arr[i]-1]++;
        updhash(curhsh,k,arr[i]-1,1);
        updhash(rsthash,k,arr[i]-1,1);
        posic.insert({histo[arr[i]-1],arr[i]-1});

        int curmini = (*posic.begin()).fst;
        if (curmini != prvmini) {
            rsthash = (rsthash - sumpot[k-1] + MOD)%MOD;
        }

        auto it = prefs.find(rsthash);
        if (it != prefs.end()) rta = max(rta, curmini - (*it).snd);
        else prefs[rsthash] = curmini;
    }

    cout << rta * (ll)k << '\n';

    return 0;
}
