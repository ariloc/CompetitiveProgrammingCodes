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

    string a,b; cin >> a >> b;
    bool aut = false, arr = false, posib = true;
    int lstInd = -1, j = 0;
    forn(i,b.size()) {
        while (j < (int)a.size() && a[j] != b[i]) j++;
        if (j == (int)a.size()) {arr = true; break;}
        j++;
    }
    map<char,int> ac,bc;
    forn(i,a.size()) ac[a[i]]++;
    forn(i,b.size()) bc[b[i]]++;

    for (auto &i : bc) {
        if (ac[i.fst] > i.snd) aut = true;
        else if (ac[i.fst] < i.snd) posib = false;
    }

    for (auto &i : ac) if (!bc.count(i.fst)) aut = true;

    if (!posib) cout << "need tree";
    else if (arr && aut) cout << "both";
    else if (arr) cout << "array";
    else cout << "automaton";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
s
