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

ii arr[MAXN];

int main() {
    FAST_IO;

    int n,x; cin >> n >> x;
    forn (i,n) {cin >> arr[i].fst; arr[i].snd = i;}

    sort(arr,arr+n);

    int i = 0;
    ii rta = {-1,-1};
    dforn (j,n) {
        while (i < j and arr[i].fst + arr[j].fst < x) i++;
        if (i >= j) break;
        if (arr[i].fst + arr[j].fst == x and i != j) rta = {arr[i].snd,arr[j].snd};
    }

    if (rta.fst != -1) cout << rta.fst+1 << ' ' << rta.snd+1; else cout << "IMPOSSIBLE";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
