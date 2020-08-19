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

const int MAXN = 1020;
const int MAX = 1000;

int seq[MAXN];

void gen() {
    forn (i,MAX) seq[i] = i+1;

    //swapping
    forn (i,MAX) {
        if (!(i % 4)) swap(seq[i],seq[i+3]);
        if ((i%4) == 1 or (i%4) == 3) swap(seq[i],seq[i-1]);
    }
}

int main() {
    FAST_IO;

    gen();
    int t; cin >> t;

    forn (i,t) {
        int N; cin >> N;

        if (N < 4) {cout << "-1\n"; continue;}

        vi result;
        forn (j,N-(N%4)) result.pb(seq[j]); // al final queda al menos con faltante dif 2
        if ((N%4) > 0) {result.pb(N); // tranqulamente lo pongo
            if ((N%4) > 1) {result.insert(result.end()-2,((N%4) > 2 ? N-2 : N-1));
                if ((N%4) > 2) {
                    result.insert(result.end()-5,N-1);
                }}}

        for (auto &j : result) cout << j << ' ';

        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!