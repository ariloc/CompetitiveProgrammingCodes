#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e6+5;

int FT[MAXN];

void setFT(int p, int v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT(int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void inicializar() {}

void nuevoNumero(int x) {
    setFT(x,1);
}

int contar(int a, int b) {
    return getFT(b)-getFT(a-1);
}
