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

char distChar (char a, char b) {
    return ((a == 'a' || b == 'a') ? ((a == 'b' || b == 'b') ? 'c' : 'b') : 'a');
}

int main() {
    FAST_IO;

    int n,t; cin >> n >> t;
    string a,b,c; cin >> a >> b;
    bool choose = 0; int ind = -1; vi eq;
    forn(i,n) {
        if (a[i] == b[i]) {c += "X"; eq.pb(i);}
        else {
            if (!choose) c += a[i];
            else {c += b[i]; t--;}
            choose = !choose; ind = i;
        }
    }
    if (choose) {c[ind] = distChar(a[ind],b[ind]); t--;}
    for (auto &i : eq)
        if (t > 0) {c[i] = (a[i] == 'a' ? 'b' : 'a'); t--;}
        else c[i] = a[i];
    int cnt = 0;
    forn(i,n) {
        if (!t) break;
        if (c[i] == a[i] || c[i] == b[i]) {
            c[i] = distChar(a[i],b[i]);
            cnt++; if (!(cnt&1)) t--;
        }
    }
    if (t != 0 || (cnt&1)) cout << "-1";
    else cout << c;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
