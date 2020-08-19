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

const int MAXN = 2e5+10;
const int ADD = 1e5+1;

ll FT[MAXN];
bitset<MAXN> done;
int posic[MAXN];
int shoes[MAXN][2]; // pos 0, neg 1

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

ll getFT (int p) {
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

ll count_swaps(vi S) {
    ll rta = 0;

    forn (i,MAXN) {shoes[i][0] = shoes[i][1] = i;}

    forn (i,S.size()) {
        if (S[i] > 0) {
            posic[i] = shoes[S[i]][0]; // "linked-list" (maps en array hacia atrás)
            shoes[S[i]][0] = i;
        }
        else {
            int v = abs(S[i]);
            posic[i] = shoes[v][1];
            shoes[v][1] = i;
        }

        setFT(i+1,1); // marco Fenwick
    }

    dforn (i,S.size()) {
        if (done[i]) continue;
        if (S[i] > 0) {
            shoes[S[i]][0] = posic[i];
            int nxt = shoes[S[i]][1]; shoes[S[i]][1] = posic[nxt];
            done[nxt] = true;

            rta += getFT(i+1)-(nxt ? getFT(nxt) : 0)-2;
            setFT(nxt+1,-1);
        }
        else {
            shoes[abs(S[i])][1] = posic[i];
            int nxt = shoes[abs(S[i])][0];
            shoes[abs(S[i])][0] = posic[nxt]; done[nxt] = true;

            rta += getFT(i+1)-(nxt ? getFT(nxt) : 0)-1;
            setFT(nxt+1,-1);
        }
    }

    return rta;
}

int main() {
    FAST_IO;

    vi send;
    int N; cin >> N;
    forn (i,N) {int x; cin >> x; send.pb(x);}

    cout << count_swaps(send);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
