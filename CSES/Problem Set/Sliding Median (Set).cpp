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

const int MAXN = 2e5;

int arr[MAXN];
multiset<int> range;

int main() {
    int n,k; scanf("%d %d",&n,&k);
    forn(i,n) scanf("%d",&arr[i]);
    forn(i,k) range.insert(arr[i]);

    auto it = range.begin(); int cnt = 1;
    while (cnt < ((k+1)/2)) {cnt++; it++;}
    int lastM = *it;
    printf("%d ",lastM);

    /*
        arr[i-k] │ arr[i]
        ─────────┼────────
            >    │   =     -> 0
            <    │   =     -> ++
            =    |   >     -> ++
            =    │   <     -> --
            <    │   >     -> ++
            >    │   <     -> --


        Conclusión: - Aumentar si arr[i-k] <= lastM
                    - Disminuir si arr[i] < lastM
                    - Al comparar usar *it para evitar caso borde comparar con nuevo antes de borrar
    */

    forsn(i,k,n) {
        range.insert(arr[i]);
        if (arr[i] < *it) it--;
        if (arr[i-k] <= *it) it++;
        range.erase(range.lower_bound(arr[i-k]));
        printf("%d ",(lastM = (*it)));
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
