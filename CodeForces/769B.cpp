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

const int MAXN = 105;

ii arr[MAXN];
bitset<MAXN> done;
vector<ii> rta;
int n;

void dfs (int st) {
    done[st] = true;

    int cnt = arr[st].fst;
    forn(i,n) {
        if (cnt <= 0) break;
        if (!done[i]) rta.pb({arr[st].snd,arr[i].snd}), dfs(i), cnt--;
    }
}

int main() {
    FAST_IO;

    cin >> n;
    forn(i,n) {cin >> arr[i].fst, arr[i].snd = i;}

    sort(arr,arr+n,greater<ii>());
    forn(i,n) if (!arr[i].snd) {dfs(i); break;}

    if ((int)rta.size() != n-1) cout << "-1";
    else {
        cout << n-1 << '\n';
        for (auto &i : rta) cout << i.fst+1 << ' ' << i.snd+1 << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
