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

const int MAXN = 8002;
const ll INF = 9e18;

int teams[MAXN];
bitset<MAXN> done;

int posib (int mid, int n) {
    int rides = 0;
    int r = n-1;
    forn(l,n) {
        if (r <= l) break;
        while (r > l && ((teams[l]+teams[r] > mid) || done[r])) r--;
        if (r > l && teams[l]+teams[r] <= mid) done[l] = true, done[r] = true, rides++;
    }
    forn(j,n) if (done[j]) done[j] = 0; else rides++;
    //cerr << mid << ' ' << n << ' ' << rides << " !!!!" << endl;
    return rides;
}

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(j,n) {int x; cin >> x; teams[--x]++;}

    sort(teams,teams+k);
    int lowB = 0;
    forn(j,k) lowB = max(lowB,teams[j]);

    ll mini = INF;
    dforsn(i,(k+1)/2,k+1) { // si hago i rides
        int low = lowB, high = 5e5+2;
        while (high-low > 1) {
            int mid = (high+low)/2;
            if (posib(mid,k) <= i) high = mid;
            else low = mid;
        }
        if (posib(low,k) <= i) high = low;
        //cerr << posib(high,n) << ' ' << i << ' ' << high << endl;
        mini = min(mini,(ll)high*posib(high,k));
    }

    cout << mini;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
