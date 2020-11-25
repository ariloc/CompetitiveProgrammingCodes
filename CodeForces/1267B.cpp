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

    string s; cin >> s;
    deque<pair<char,int>> comps;
    int cnt = 1;
    forsn(i,1,s.size())
        if (s[i] != s[i-1])  {
            comps.pb({s[i-1],cnt});
            cnt = 1;
        } else cnt++;
    if (cnt) comps.pb({s.back(),cnt});

    bool posib = true;
    while ((int)comps.size() > 1) {
        auto a = comps.front(); comps.pop_front();
        auto b = comps.back(); comps.pop_back();
        if (a.fst != b.fst || a.snd+b.snd < 3) {posib = false; break;}
    }
    if ((int)comps.size() != 1 || comps.back().snd < 2) posib = false;

    if (posib) cout << comps.back().snd+1;
    else cout << 0;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
