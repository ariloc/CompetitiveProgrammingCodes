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

const int INF = 2e9+2;

int main() {
    FAST_IO;

    int n; cin >> n;

    int mini = INF, maxi = -1;
    ii maxiS = {INF,-1}; int ind = -1;
    forn(i,n) {
        int a,b; cin >> a >> b;
        mini = min(a,mini); maxi = max(b,maxi);
        if (a <= maxiS.fst and b >= maxiS.snd) {maxiS = {a,b}; ind = i;}
    }

    if (maxiS.fst <= mini and maxiS.snd >= maxi) cout << ind+1;
    else cout << -1;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!