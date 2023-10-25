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
ll const MOD = 1536497682017496834LL;
int const P = 400009;

int arr[MAXN];
map<ll,int> prefs;
int histo[MAXN];
__int128 potp[MAXN];
set<ii> posic;

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) cin >> arr[i], --arr[i];

    potp[0] = 1;
    forsn(i,1,MAXN) potp[i] = (potp[i-1] * (__int128)P)%MOD;
    ll sumk = 0;
    forn(i,k) sumk = (sumk + potp[i])%MOD;

    forn(i,k) posic.insert({0,i});

    prefs[0] = -1;

    ll rsthash = 0;
    int rta = 0;
    forn(i,n) {
        int prvmini = (*posic.begin()).fst;
        posic.erase({histo[arr[i]],arr[i]});
        ++histo[arr[i]];
        rsthash = (rsthash + potp[arr[i]])%MOD;
        posic.insert({histo[arr[i]],arr[i]});

        int curmini = (*posic.begin()).fst;
        if (curmini != prvmini) {
            rsthash = ((rsthash - sumk)%MOD + MOD)%MOD;
        }

        auto it = prefs.find(rsthash);
        if (it != prefs.end()) rta = max(rta, i - (*it).snd);
        else prefs[rsthash] = i;
    }

    cout << rta << '\n';

    return 0;
}
