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

map<string,string> op;

bool test(string s) {
    if (s.size() == 1) return (s[0] == 'a');
    string suff = s.substr(2);
    for (auto &i : op) {
        if (i.fst[0] == s[0] && i.fst[1] == s[1])
            if(test(i.snd+suff)) return 1;
    }
    return 0;
}

int construct (int i, int n, string &s) {
    if (i >= n) return test(s);
    int sum = 0;
    forn(j,6) {s += (j+'a'); sum += construct(i+1,n,s); s.pop_back();}
    return sum;
}

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    forn(i,q) {
        string a,b; cin >> a >> b;
        op[a] = b;
    }

    string s;
    cout << construct(0,n,s);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
