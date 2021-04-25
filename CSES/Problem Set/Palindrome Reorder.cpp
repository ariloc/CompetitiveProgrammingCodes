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
    sort(all(s));

    queue< pair<int,char> > Q;
    int cnt = 1; int odd = 0, cntOd; char imp;
    forsn (i,1,s.size()) {
        if (s[i] != s[i-1]) {
            if (cnt & 1) {odd++; cntOd = cnt; imp = s[i-1];}
            else Q.push({cnt,s[i-1]});
            cnt = 0;
        }
        cnt++;
    }
    if (cnt & 1) {odd++; cntOd = cnt; imp = s.back();} else Q.push({cnt,s.back()});
    if (odd > 1) {cout << "NO SOLUTION"; return 0;}

    string l;
    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();
        l += string(e.fst/2,e.snd);
    }
    cout << l;
    if (odd) forn (i,cntOd) cout << imp;
    dforn (i,l.size()) cout << l[i];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
