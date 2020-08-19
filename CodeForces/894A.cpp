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

const int MAXN = 105;

int TAd[MAXN];

int main() {
    FAST_IO;

    string s; cin >> s;
    vi ind;
    forn (i,s.size()) {if (s[i] == 'A') TAd[i]++; if(s[i] == 'Q') ind.pb(i);}
    forn(i,s.size()) TAd[i] += TAd[i-1];

    ll rta = 0;
    forn (i,ind.size()) forsn(j,i,ind.size())
        rta += TAd[ind[j]] - (ind[i]-1 >= 0 ? TAd[ind[i]-1] : 0);

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!