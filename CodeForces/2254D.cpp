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

int const MAXN = 2e5+5;

ll arr[MAXN];
map<ll,int> histo;
map<ll,ll> mapita;

int main() {
    FAST_IO;

    int t;cin  >> t;
    forn(_,t) {
        histo.clear();
        mapita.clear();

        int n; cin >> n;

        forn(i,n) cin >> arr[i];

        forn(i,n) histo[arr[i]]++;

        vector<pair<ll,int>> auxi;
        for (auto &i : histo) auxi.pb(i);
        sort(all(auxi));

        if (auxi[0].fst != 0) {
            cout << "-1\n";
            continue;
        }

        if (sz(auxi) == 1) {
            forn(i,n) cout << "1 ";
            cout << "\n";
            continue;
        }

        bool posib = true;
        forsn(i,1,sz(auxi)) {
            ll dif = auxi[i].fst - auxi[i-1].fst;
            if (dif%auxi[i-1].snd) posib = false;
            dif /= auxi[i-1].snd;
            mapita[auxi[i-1].fst] = dif;
        }

        if (!posib) {
            cout << "-1\n";
            continue;
        }

        mapita[auxi.back().fst] = mapita[auxi[sz(auxi)-2].fst]+1;

        vector<pair<ll,ll>> auxi2;
        for (auto &i : mapita) auxi2.pb(i);
        sort(all(auxi2));

        forsn(i,1,sz(auxi2)) if (auxi2[i].snd <= auxi2[i-1].snd) posib = false;
        
        if (!posib) {
            cout << "-1\n";
            continue;
        }

        forn(i,n) cout << mapita[arr[i]] << ' ';
        cout << '\n';
    }

    return 0;
}
