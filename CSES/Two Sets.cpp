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

vi a,b;

int main() {
    //FAST_IO;

    int n; scanf("%d",&n);
    if (((n*(n+1))/2) & 1) {printf("NO"); return 0;}
    bool lst = false;
    forn (i,n/2) { // de a pares igual suma
        if (i & 1) {a.pb(i+1); a.pb(n-i); lst = false;}
        else {b.pb(i+1); b.pb(n-i); lst = true;}
    }
    int dif = (n+1)/2;
    if (n & 1) {
        if (lst) a.pb(dif); else b.pb(dif);
        forn (i,n) {
            int x = min((int)a.size()-1,i), y = min((int)b.size()-1,i);
            if (lst) {if (b[y] > a[x]) swap(a[x],b[y]);}
            else if (a[x] > b[y]) swap(a[x],b[y]);
        }
    }

    printf("YES\n");
    printf("%d\n",(int)a.size());
    for (auto &i : a) printf("%d ",i);
    printf("\n%d\n",(int)b.size());
    for (auto &i : b) printf("%d ",i);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
