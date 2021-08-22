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

const int MAXN = 2e5+5;

int arr1[MAXN], arr2[MAXN];
int mapita[MAXN], mapita2[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;
    forn (i,N) cin >> arr1[i];
    forn (i,N) cin >> arr2[i];

    forn (i,N) {
        if (!arr1[i]) continue;
        int nxt = i+1; nxt %= N;
        if (!arr1[nxt]) nxt = (nxt+1)%N;
        mapita[arr1[i]] = arr1[nxt];
    }

    forn (i,N) {
        if (!arr2[i]) continue;
        int nxt = i+1; nxt %= N;
        if (!arr2[nxt]) nxt = (nxt+1)%N;
        mapita2[arr2[i]] = arr2[nxt];
    }

    bool posib = true;
    forn (i,MAXN) if (mapita[i] != mapita2[i]) {posib = false; break;}

    cout << (posib ? "YES" : "NO");

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!