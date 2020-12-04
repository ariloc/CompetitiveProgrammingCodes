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

const int dif[] = {0,1,2};

int main() {
    FAST_IO;

    string s; cin >> s;
    forsn(i,1,s.size())
        if (s[i] == s[i-1])
        forn(j,26) {
            bool posib = true;
            forn(k,3) {
                if (i+dif[k] >= 0 && i+dif[k] < (int)s.size())
                if (s[i+dif[k]]-'a' == j) {posib = false; break;}
            }
            if (posib) {s[i] = j+'a'; break;}
        }
    cout << s;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
