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

const int MAXN = 1e5+2;

pair<char,int> let[MAXN];

int main() {
    FAST_IO;

    string s; cin >> s;

    forn (i,s.size()) let[i] = {s[i],i};

    sort(let,let+MAXN,[](const pair<char,int> &a, const pair<char,int> &b){if (a.fst == b.fst)
         return a.snd < b.snd; return a.fst > b.fst;});

    string rta; rta += let[0].fst; int lastI = let[0].snd;
    forsn (i,1,s.size()) {
        if (let[i].snd >= lastI) {lastI = let[i].snd; rta+= let[i].fst;}
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!