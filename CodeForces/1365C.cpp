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

const int MAXN = 2e5+2;

int ind[MAXN], shift[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;
    forn (i,N) {int x; cin >> x; ind[x] = i;}
    forn (i,N) {
        int x; cin >> x;
        if (ind[x] >= i) shift[ind[x]-i]++;
        else shift[ind[x]+(N-i)]++;
    }

    int maxi = 0;
    forn (i,N) maxi = max(maxi,shift[i]);

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!