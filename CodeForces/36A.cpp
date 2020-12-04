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

int main() {
    FAST_IO;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n; cin >> n;
    string s; cin >> s;

    bool posib = true;
    int cnt = -1, interval = -1;
    forn(i,s.size()) {
        if (s[i] == '1') {
            if (interval == -1) {if (cnt != -1) interval = cnt;}
            else if (cnt != interval) posib = false;
            cnt = 0;
        }
        else if (cnt != -1) cnt++;
    }
    cout << (posib ? "YES" : "NO");

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
