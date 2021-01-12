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

const int MAXN = 20;

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

void fp (int x) {
    int i = 9;
    char buf[10];
    while (x) buf[i--] = (x%10)+'0', x /= 10;
    while ((++i) < 10) putchar_unlocked(buf[i]);
}

int arr[MAXN];
ii dp[1<<MAXN];

int main() {
    int n,x; fs(n), fs(x);
    forn(i,n) fs(arr[i]);

    forsn(i,1,(1<<n)) {
        dp[i] = {n+1,0};
        forn(j,n) if (i&(1<<j)) {
            ii ot = dp[i^(1<<j)];
            if (ot.snd + arr[j] <= x) ot.snd += arr[j];
            else ot.fst++, ot.snd = arr[j];
            dp[i] = min(dp[i],ot);
        }
    }

    printf("%d",dp[(1<<n)-1].fst+1);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
