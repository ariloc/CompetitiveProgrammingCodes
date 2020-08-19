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

const int MAXN = 102;
const int INF = 1e9+2;

int num[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n; cin >> n;

        int ev = 0, od = 0;
        forn (o,n) {
            cin >> num[o];
            if (num[o] & 1) od++;
            else ev++;
        }

        if ((od & 1) != (ev & 1)) {cout << "NO\n"; continue;}
        if (!(od & 1) and !(ev & 1)) {cout << "YES\n"; continue;}

        sort(num,num+n);
        bool posib = false;
        forsn (j,1,n)
            if ((num[j] - num[j-1]) == 1) posib = true;

        if (posib) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!