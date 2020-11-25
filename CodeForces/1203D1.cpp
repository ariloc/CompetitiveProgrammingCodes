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

const int MAXN = 205;

int bst[MAXN];

int main() {
    FAST_IO;

    string s,t; cin >> s >> t;

    // Brute Force
    int maxi = 0;
    forn(i,s.size()) forsn(j,i,s.size()) { // para cada substring
        int ind = 0;
        forn(k,s.size()) {
            if (k >= i && k <= j) continue;
            if (s[k] == t[ind]) ind++;
            if (ind >= t.size()) {maxi = max(maxi,j-i+1); break;}
        }
    }

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
