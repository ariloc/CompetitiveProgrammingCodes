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

const int MAXN = 1030;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        bool mark[MAXN], mark2[MAXN];
        forn(j,MAXN) mark[j] = mark2[j] = false;

        int N; cin >> N;
        forn (j,N) cin >> arr[j];
        forn (j,N) mark[arr[j]] = true;

        forsn(k,1,MAXN+1) {
            bool posib = true;
            forn(j,N) {
                if (!mark[(arr[j]^k)] or mark2[(arr[j]^k)]) {posib = false; break;}
                mark2[(arr[j]^k)] = true;
            }
            if (posib) {cout << k << '\n'; goto CONT;}
            forn (j,MAXN) mark2[j] = false;
        }

        cout << "-1\n";
        CONT: continue;
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!