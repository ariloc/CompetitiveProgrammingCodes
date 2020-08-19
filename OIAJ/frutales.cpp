#include <bits/stdc++.h>

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

const int MAXN = 2010;
const int INF = 1e9+5;

int dp[MAXN][MAXN];
int TAd[MAXN][MAXN]; bool terreno[MAXN][MAXN];
int X,Y,p,f;

void fillTAd() {
    forsn (i,1,MAXN)  {
        int cnt = 0;
        forsn(j,1,MAXN) {
            cnt += TAd[i][j];
            TAd[i+1][j] += TAd[i][j];
            TAd[i][j] = cnt;
        }
    }
}

int main() {
    freopen("frutales.in","r",stdin);
    freopen("frutales.out","w",stdout);

    scanf("%d %d %d %d",&X,&Y,&p,&f); // input

    forn (i,p) {
        int x,y; scanf("%d %d",&x,&y);
        terreno[y][x] = true; // marco terreno
    }

    forn (i,f) {
        int x,y; scanf("%d %d",&x,&y);
        TAd[y][x]++; // Hago para Tabla Aditiva
    }

    fillTAd(); // Lleno la Tabla Aditiva

    int best = -1, base = INF, sepI, sepD;
    dforsn (i,1,Y+1) dforsn (j,1,X+1) { // DP Bottom-Up
        if (terreno[i][j]) continue;
        dp[i][j] = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]})+1; // adyacentes a dos lados y diagonal --> cuadrado de + superficie

        int k = dp[i][j];
        int frut = TAd[i-1][j-1] + TAd[i+k-1][j+k-1] - TAd[i-1][j+k-1] - TAd[i+k-1][j-1]; // frutales en el cuadrado según TAd

        if (frut >= best) { // me fijo si puedo achicar el cuadrado
            int low = 0;
            int high = k;

            // Uso Binary Search. Cubriría el caso con frutales concentrados en la esquina
            while (high-low > 1) {
                int mid = (low+high)/2;
                if ((TAd[i-1][j-1] + TAd[i+mid-1][j+mid-1] - TAd[i-1][j+mid-1] - TAd[i+mid-1][j-1])
                    < frut) low = mid;
                else high = mid;
            }

            k = min(k,high);
        }

        if (frut > best or (frut == best and k < base)) // si opción superadora, la guardo
            {best = frut; base = k; sepI = j-1; sepD = i-1;}
    }

    printf("%d %d\n%d\n%d",sepI,sepD,base,best); // output

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
