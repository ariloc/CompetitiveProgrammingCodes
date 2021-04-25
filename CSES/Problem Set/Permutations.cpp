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

vi arr;

int main() {
    FAST_IO;

    int n; cin >> n;
    if (n == 1) {cout << 1; return 0;}
    if (n < 4) {cout << "NO SOLUTION"; return 0;}

    arr.pb(0);
    for (int i = 1; i <= n; i += 4) {
        if (i+3 <= n) {arr.pb(i+2); arr.pb(i); arr.pb(i+3); arr.pb(i+1);}
        else if (i+2 <= n) {arr.pb(i+2); arr.pb(i); arr[0] = i+1;}
        else if (i+1 <= n) {arr.pb(i); arr[0] = i+1;}
        else arr.pb(i);
    }

    for (auto &i : arr)
        if (i) cout << i << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
