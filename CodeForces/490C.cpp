
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

const int MAXN = 1e6+5;

int base10Pow[MAXN];

int main() {
    FAST_IO;

    int tmp = 1;
    string s; int a,b; cin >> s >> a >> b;
    forn(i,MAXN) {
        base10Pow[i] = tmp;
        tmp = (tmp*10+b)%b;
    }

    int modA = 0, modB = 0;
    forsn(i,1,s.size()) {
        modB = (modB+(s[i]-'0')*base10Pow[s.size()-1-i])%b;
    }
    modA = (modA+s[0]-'0')%a;
    string r1,r2;
    r1 += s[0]; dforsn(i,1,s.size()) r2 += s[i];
    forsn(i,1,s.size()-1) {
        if (!modA and !modB and r2.back() != '0') break;
        r1 += s[i]; r2.pop_back();
        modA = (modA*10)%a; modA = (modA+(s[i]-'0'))%a;
        modB = (modB-(s[i]-'0')*base10Pow[(int)s.size()-i-1])%b;
    }
    if (!modA and !modB and r2.back() != '0') {
        cout << "YES\n";
        cout << r1 << '\n'; reverse(all(r2));
        cout << r2;
    }
    else cout << "NO";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
