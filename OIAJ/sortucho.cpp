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

const int MAXN = 1e6+5;

int nums[MAXN];
ii aparic[MAXN];
vi bags[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {int x; cin >> x; nums[x]++;}

    int idx = 0;
    forn(i,MAXN) if (nums[i]) aparic[idx++] ={i,nums[i]-nums[i]/2};
    sort(aparic,aparic+idx);

    for (auto &i : aparic) forn(j,i.snd) bags[j].pb(i.fst);
    forn(i,MAXN) if (!bags[i].empty()) for (auto &j : bags[i]) cout << j << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
