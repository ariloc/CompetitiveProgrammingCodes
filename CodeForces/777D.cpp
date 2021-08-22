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

const int MAXN = 5e5+5;

vector<string> hashtags;
int brk[MAXN];

int main() {
    FAST_IO;

    memset(brk,-1,sizeof(brk));

    int n; cin >> n;
    forn(i,n) {string s; cin >> s; hashtags.pb(s);}
    brk[n-1] = hashtags[n-1].size();

    //vector<string> result(n);
    dforsn(i,1,n) {
        forn(j,min((int)hashtags[i-1].size(),brk[i])) {
            if (hashtags[i][j] > hashtags[i-1][j]) {brk[i-1] = hashtags[i-1].size(); break;}
            if (hashtags[i][j] < hashtags[i-1][j]) {brk[i-1] = j; break;}
        }
        if (brk[i-1] == -1) brk[i-1] =  min((int)hashtags[i-1].size(),brk[i]);
    }
    forn (i,n) {
        forn (j,brk[i]) cout << hashtags[i][j];
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!