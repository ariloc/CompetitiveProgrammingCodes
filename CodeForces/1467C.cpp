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

const int INF = 1e9+5;
const int MAXN = 3e5+2;

ll c[3][MAXN];

int main() {
    FAST_IO;

    int n1,n2,n3; cin >> n1 >> n2 >> n3;
    ll s1 = 0, s2 = 0, s3 = 0;
    forn(j,n1) cin >> c[0][j], s1 += c[0][j];
    forn(j,n2) cin >> c[1][j], s2 += c[1][j];
    forn(j,n3) cin >> c[2][j], s3 += c[2][j];

    sort(c[0],c[0]+n1);
    sort(c[1],c[1]+n2);
    sort(c[2],c[2]+n3);

    cout << s1+s2+s3-min({s1,s2,s3,c[0][0]+c[1][0],c[0][0]+c[2][0],c[1][0]+c[2][0]})*2;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
