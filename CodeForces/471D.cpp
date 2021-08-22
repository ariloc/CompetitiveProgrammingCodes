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

const int MAXN = 1e7+5;

int KMP[MAXN],elph[MAXN],bears[MAXN];

void KMP_compute(string s) {
    int n = (int)s.size();

    for (int i = 1; i < n; i++) {
        int j = KMP[i-1];
        while (j > 0 && s[i] != s[j])
            j = KMP[j-1];
        if (s[i] == s[j])
            j++;
        KMP[i] = j;
    }
}

int main() {
    FAST_IO;

    int n,w; cin >> n >> w;

    forn (j,n) cin >> bears[j];
    forn (i,w) cin >> elph[i];

    if (w == 1) {cout << n; return 0;}
    if (w > n) {cout << 0; return 0;}

    string lookup;
    char buf[15];
    int sz = 0;
    forsn (i,1,w) {
        int dif = elph[i]-elph[i-1];

        string tmp;
        if (dif < 0) tmp+='-';
        else tmp+='+';
        sprintf(buf,"%d",abs(dif));
        tmp+=buf;
        sz += tmp.size();

        lookup += tmp;
    }
    lookup += '#';

    forsn (i,1,n) {
        int dif = bears[i]-bears[i-1];
        if (dif < 0) lookup+='-';
        else lookup+='+';
        sprintf(buf,"%d",abs(dif));
        lookup+=buf;
    }

    KMP_compute(lookup);

    int cnt = 0;
    forn(i,lookup.size()) if (KMP[i] == sz) cnt++;

    cout << cnt;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!