#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int main() {
    int s,b;
    while (scanf("%d %d",&s,&b) != EOF) {
        if (!s && !b) break;

        set<int> sold;
        forn(i,s) sold.insert(i+1);
        forn(i,b) {
            int l,r; scanf("%d %d",&l,&r);
            auto it = sold.lower_bound(l), it2 = sold.upper_bound(r);

            int izq = -1, der = -1;
            if (it != sold.begin()) izq = *(prev(it));
            if (it2 != sold.end()) der = *it2;


            while (it != sold.end() && (*it) <= r) // por experiencia, se van corriendo a la izq
                it++, sold.erase(prev(it));

            if (izq == -1) putchar('*'); else printf("%d",izq);
            putchar(' ');
            if (der == -1) putchar('*'); else printf("%d",der);
            putchar('\n');
        }

        puts("-");
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
