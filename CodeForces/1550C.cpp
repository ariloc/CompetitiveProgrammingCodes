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

const int MAXN = 2e5+5;

struct pt {
    int x,y;

    pt () {};
    pt (int xx, int yy) : x(xx), y(yy) {};
};

pt arr[MAXN];

ll dist (pt a, pt b) {
    return abs(a.x-b.x) + abs(a.y-b.y);
}

bool isInvalid (pt a, pt b, pt c) {
    return dist(a,c) == (dist(a,b) + dist(b,c));
}

void tryIt (int n, int dif, ll &rta) {
    forn(ind,n-dif+1) {
        bool cond = false;

        forn(i,dif) forsn(j,i+1,dif) forn(k,dif)
            if (k != i && k != j) cond |= isInvalid(arr[ind+i],arr[ind+j],arr[ind+k]);
        
        if (!cond) rta++;
    }
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(o,t) {
        int n; cin >> n;
        forn(i,n) {int x; cin >> x; arr[i] = {x,i};}

        ll rta = 2*n - 1;

        tryIt(n,3,rta);
        tryIt(n,4,rta);

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO! 
