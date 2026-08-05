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

map<string,int> fri;
int curid = 0;
ull ady[MAXF];
int n,m;

int solve(ull mk, ull excl, int bit, int cnt) {
    if (bit >= m) return cnt;

    if (mk&(1LL<<bit) || excl&(1LL<<bit)) return solve(mk,excl,bit+1,cnt);

    ull curady = ady[bit] & ~excl;

    // prunes
    if (!curady) return solve(mk|(1LL<<bit), excl|ady[bit], bit+1, cnt+1);
    int bits = __builtin_popcountll(curady);
    if (bits == 1)
        return solve(mk|(1LL<<bit),excl|ady[bit],bit+1,cnt+1);

    if (bits == 2) {
        ull auxi = curady;
        int fbit = __builtin_ctzll(auxi);
        auxi ^= (1LL<<fbit);
        int sbit = __builtin_ctzll(auxi);
        if (!(ady[fbit]&(1LL<<sbit)))
            return max(solve(mk|(1LL<<bit),excl|ady[bit],bit+1,cnt+1),solve(mk|ady[bit],excl|ady[fbit]|ady[sbit],bit+1,cnt+2));
        return solve(mk|(1LL<<bit),excl|ady[bit],bit+1,cnt+1);
    }

    return max(solve(mk,excl,bit+1,cnt),solve(mk|(1LL<<bit),excl|ady[bit],bit+1,cnt+1));
}

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

    
    cout << solve(0,0,0,0) << '\n';

    return 0;
}
