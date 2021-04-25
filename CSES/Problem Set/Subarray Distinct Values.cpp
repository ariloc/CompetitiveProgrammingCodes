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

const int MAXN = 2e5+2;

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

void fp (ll x) {
    if (!x) {putchar_unlocked('0'); return;}
    int i = 19;
    char buf[20];
    while (x) buf[i--] = (x%10)+'0', x /= 10LL;
    while ((++i) < 20) putchar_unlocked(buf[i]);
}

int arr[MAXN], cnt[MAXN];
vi num;

int main() {
    int k,n; fs(n), fs(k);
    forn(j,n) fs(arr[j]), num.pb(arr[j]);

    // compress
    sort(all(num));
    num.erase(unique(all(num)),num.end());
    forn(j,n) arr[j] = lower_bound(all(num),arr[j])-num.begin();

    int r = 0, dif = 0;
    ll c = 0;
    forn(l,n) {
        while(r < n && ((dif < k) || (dif == k && cnt[arr[r]])))
            dif += (!cnt[arr[r]]), cnt[arr[r++]]++;
        c += r-l;
        cnt[arr[l]]--, dif -= (!cnt[arr[l]]);
    }

    fp(c);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
