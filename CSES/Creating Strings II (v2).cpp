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

const int MAXA = 26;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

int cant[MAXA],fact[MAXN];
char s[MAXN];

int binExp (int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

int main() {
    fact[0] = 1; // precalc
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;

    scanf("%s",s); int n = 0;
    for (int i = 0; s[i]; i++) cant[s[i]-'a']++, n++;

    int den = 1;
    forn(i,MAXA) den = ((ll)den*fact[cant[i]])%MOD;

    printf("%d",(int)(((ll)fact[n]*binExp(den,MOD-2))%MOD));

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
