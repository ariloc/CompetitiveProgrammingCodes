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

const int MAXN = 40005;

vi waste[MAXN];
int dp[MAXN];

int main() {
    int n,m,k,t; scanf("%d %d %d %d",&n,&m,&k,&t);

    forn(i,k) {
        int a,b; scanf("%d %d",&a,&b); a--, b--;
        waste[a].pb(b);
    }

    forn(i,n) dp[i] = (int)waste[i].size(), sort(all(waste[i]));
    forsn(i,1,n) dp[i] += dp[i-1];

    forn(i,t) {
        int x,y; scanf("%d %d",&x,&y); x--, y--;
        //cerr << x << ' ' << y << "!!!!!" << endl;

        int ind = upper_bound(all(waste[x]),y)-waste[x].begin()-1;
        if (ind >= 0 && waste[x][ind] == y)
            puts("Waste");
        else {
            int waste_acc = (x ? dp[x-1] : 0) + ind + 1;
            //cerr << waste_acc << ' ' << i << ' ' << dp[i-1] << ' ' << ind << ' ' << x << ' ' << y << endl;
            switch ( ((x*m + y + 1)-waste_acc-1) %3) {
                case 0 : puts("Carrots"); break;
                case 1 : puts("Kiwis"); break;
                case 2 : puts("Grapes"); break;
            }
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!