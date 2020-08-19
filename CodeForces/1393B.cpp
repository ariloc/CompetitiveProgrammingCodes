#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+5;

int planks[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    int pack[9] = {0,0,0,0,0,0,0,0,0};
    forn (i,n) {
        int x; cin >> x;
        planks[x]++;
        if (planks[x] < 9) pack[planks[x]]++;
    }

    int q; cin >> q;
    forn (i,q) {
        char s; int x; cin >> s >> x;
        if (s == '-') {
            if (planks[x] < 9) pack[planks[x]]--;
            planks[x]--;
        }
        else {
            planks[x]++;
            if (planks[x] < 9) pack[planks[x]]++;
        }
        /*forn(j,9) cerr << pack[j] << ' ';
        cerr << endl;*/

        bool posib = false;
        if (pack[8]) posib = true;
        else if ((pack[6] and (pack[2]-pack[6])) or pack[6] > 1) posib = true;
        else if (pack[4] > 1 or (pack[4] and (pack[2]-pack[4]) > 1)) posib = true;

        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!