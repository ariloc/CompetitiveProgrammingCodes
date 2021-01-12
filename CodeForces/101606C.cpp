#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 10;
const int INF = 1e9+5;

map<string,int> vals;

int main() {
    FAST_IO;

    int n; cin >> n;

    // init
    vals["red"] = 1;
    vals["yellow"] = 2;
    vals["green"] = 3;
    vals["brown"] = 4;
    vals["blue"] = 5;
    vals["pink"] = 6;
    vals["black"] = 7;

    int cntR = 0, maxi = -1, sum = 0;
    forn(j,n) {
        string s; cin >> s;
        if (s == "red") cntR++;
        else sum += vals[s];
        maxi = max(maxi,vals[s]);
    }

    if (maxi == 1) cout << 1;
    else cout << cntR+cntR*maxi+sum;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
