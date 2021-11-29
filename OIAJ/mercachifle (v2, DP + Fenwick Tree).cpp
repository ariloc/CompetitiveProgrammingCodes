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

const int MAXN = 4010;
const int MAXM = 2*MAXN;
const int INF = 2e9;

struct pedido {
    int a,b,id;

    bool operator< (const pedido &o) const {
        if (a != o.a) return a < o.a;
        if (b != o.b) return b < o.b;
        return id < o.id;
    }
};

void setFT (int p, int v, int *FT) {
    for (int i = p; i < MAXM; i += i & -i)
        FT[i] += v;
}

int getFT (int p, int *FT) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void update (int &x, vi &arr) {
    x = lower_bound(all(arr),x)-arr.begin()+2; // desfase de comodidad
}

int dp[MAXN][2], P[MAXN][2], FT[2][MAXM]; // todos los que terminan antes que acá
pedido pedidos[2][MAXN];
vi pts,starts;

int main() {
    freopen("mercachifle.in","r",stdin);
    freopen("mercachifle.out","w",stdout);

    int A; scanf("%d",&A);
    forn(i,A) scanf("%d %d",&pedidos[0][i].a,&pedidos[0][i].b), pedidos[0][i].id = i;
    int B; scanf("%d",&B);
    forn(i,B) scanf("%d %d",&pedidos[1][i].a,&pedidos[1][i].b), pedidos[1][i].id = i;

    forn(i,A) pts.pb(pedidos[0][i].a), pts.pb(pedidos[0][i].b);
    forn(i,B) pts.pb(pedidos[1][i].a), pts.pb(pedidos[1][i].b);

    // compresión
    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());
    forn(i,A) update(pedidos[0][i].a,pts), update(pedidos[0][i].b,pts);
    forn(i,B) update(pedidos[1][i].a,pts), update(pedidos[1][i].b,pts);

    forn(i,A) starts.pb(pedidos[0][i].a);
    forn(i,B) starts.pb(pedidos[1][i].a);
    sort(all(starts));
    starts.erase(unique(all(starts)),starts.end());
    starts.pb(MAXM-1); // dummy (mi INF)

    sort(pedidos[0], pedidos[0]+A);
    sort(pedidos[1], pedidos[1]+B);

    /*
    cerr << "AAAA" << endl;
    forn(i,A) cerr << pedidos[0][i].a << ' ' << pedidos[0][i].b << endl;

    cerr << "BBB" << endl;
    forn(i,A) cerr << pedidos[1][i].a << ' ' << pedidos[1][i].b << endl;
    */

    forn(i,A) setFT(pedidos[0][i].b, 1, FT[0]);
    forn(i,B) setFT(pedidos[1][i].b, 1, FT[1]);

    dp[0][0] = dp[0][1] = 0;
    P[0][0] = P[0][1] = -1;
    forsn(i,1,MAXN) dp[i][0] = dp[i][1] = -INF;

    int n = (int)starts.size();
    int ptr1 = 0, ptr2 = 0;
    forn(i,n) {
        forsn(j,i+1,n) {
            int v1 = max(dp[j][0], dp[i][1] + getFT(starts[j]-1, FT[0]));
            int v2 = max(dp[j][1], dp[i][0] + getFT(starts[j]-1, FT[1]));

            if (v1 > dp[j][0]) dp[j][0] = v1, P[j][0] = i;
            if (v2 > dp[j][1]) dp[j][1] = v2, P[j][1] = i;
        }
        while (ptr1 < A && pedidos[0][ptr1].a <= starts[i]) setFT(pedidos[0][ptr1].b, -1, FT[0]), ++ptr1;
        while (ptr2 < B && pedidos[1][ptr2].a <= starts[i]) setFT(pedidos[1][ptr2].b, -1, FT[1]), ++ptr2;
    }

    /*
    forn(i,starts.size()) cerr << starts[i] << ' ';
    cerr << endl;
    forn(i,10) cerr << dp[i][0] << ' ';
    cerr << endl;
    forn(i,10) cerr << dp[i][1] << ' ';
    cerr << endl;
    */

    int maxi = max(dp[n-1][0], dp[n-1][1]);
    printf("%d\n",maxi);

    int ind = n-1, lvl = 0;
    if (maxi == dp[n-1][1]) lvl = 1;

    vector<ii> cov[2]; // los rangos que cubren son [a,b)
    vi rta[2];
    while (P[ind][lvl] != -1) {
        cov[lvl].pb({starts[P[ind][lvl]],starts[ind]});
        ind = P[ind][lvl], lvl ^= 1;
    }

    forn(k,2) sort(all(cov[k]));

    /*
    for (auto &i : cov[0]) cerr << i.fst << ' ' << i.snd << endl;
    cerr << "!!!!" << endl;
    for (auto &i : cov[1]) cerr << i.fst << ' ' << i.snd << endl;
    */

    forn(i,A) {
        int aux = upper_bound(all(cov[0]),(ii){pedidos[0][i].a, INF}) - cov[0].begin() - 1;
        if (aux >= 0 && cov[0][aux].fst <= pedidos[0][i].a && cov[0][aux].snd > pedidos[0][i].b) // recordar [a,b)
            rta[0].pb(pedidos[0][i].id);
    }
    forn(i,B) {
        int aux = upper_bound(all(cov[1]),(ii){pedidos[1][i].a, INF}) - cov[1].begin() - 1;
        if (aux >= 0 && cov[1][aux].fst <= pedidos[1][i].a && cov[1][aux].snd > pedidos[1][i].b) // recordar [a,b)
            rta[1].pb(pedidos[1][i].id);
    }

    forn (i,2) { // OUTPUT ROTÍSIMO MUY ESTRICTO CON ENTER Y ESPACIOS
        forn (j,rta[i].size()) {
            if (j) printf(" ");
            printf("%d",rta[i][j]+1);
        }
        puts("");
        fflush(stdout);
    }

    return 0;
}