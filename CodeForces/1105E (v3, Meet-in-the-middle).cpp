#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define sz(c) (int)(c).size()
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int const MAXF = 40;
int const MAXC = 1<<20;

map<string,int> fri;
int curid = 0;
ull ady[MAXF];
int n,m;
ull mk1[MAXC], mk2[MAXC];
vector<ull> po1,po2;
int dp[MAXC];

int main() {
    FAST_IO;

    cin >> n >> m;

    set<int> prv;
    forn(i,n) {
        int typ; cin >> typ;
        if (typ == 1) {
            prv.clear();
        }
        else {
            string s; cin >> s;
            if (fri.find(s) == fri.end()) fri[s] = curid++;
            int id = fri[s];
            if (!prv.count(id)) {
                for (auto &j : prv) ady[j] |= (1LL<<id), ady[id] |= (1LL<<j);
                prv.insert(id);
            }
        }
    }

    int half = m/2;
    forn(mk,1<<half) {
        ull excl = 0;
        bool posib = true;
        forn(j,half) {
            if (mk&(1LL<<j)) {
                if (excl & (1LL<<j)) posib = false;
                excl |= ady[j];
                excl |= (1LL<<j);
            }
        }
        if (posib) po1.pb(mk);
    }

    forn(mk,1<<((m+1)/2)) {
        ull excl = 0;
        bool posib = true;
        forn(j,(m+1)/2) {
            if (mk&(1LL<<j)) {
                if (excl & (1LL<<(j+half))) posib = false;
                excl |= ady[j+half];
                excl |= (1LL<<(j+half));
            }
        }
        if (posib) po2.pb((ull)mk<<half);
    }

    for (auto &mk : po1) dp[mk] = __builtin_popcountll(mk);

    forn(i,half)
        forn(mk,1<<half)
            if (mk & (1LL<<i))
                dp[mk] = max(dp[mk], dp[mk^(1LL<<i)]);

    int maxi = 1;
    for (auto &mk : po2) {
        ull adj = 0;
        forn(i,m) if (mk&(1LL<<i)) adj |= ady[i];
        ull ot = (((1LL<<m)-1)^adj)&((1LL<<half)-1);
        maxi = max(maxi, __builtin_popcountll(mk) + dp[ot]);
    }

    cout << maxi << '\n';

    return 0;
}
