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

const int MAXN = 2e6+5;
const int INF = 1e9+5;

int arr[MAXN];

int main() {
    freopen("como.in","r",stdin);
    freopen("como.out","w",stdout);

    int M; scanf("%d",&M);
    forn (i,M) scanf("%d",&arr[i]);
    ii nd = {0,arr[0]}; scanf("%d",&nd.fst);

    int v = 0, actX = 0; bool mark = false;
    forsn (i,1,M) {
        int dif = abs(arr[i-1]-arr[i]); actX += dif;
        if (actX <= nd.fst) continue;
        if (!mark) {if (!v and (!(i & 1))) {nd.snd = abs(nd.fst-(actX-dif)); break;} mark = true;}

        int otDif = abs(nd.fst-actX);
        if (i & 1) v += otDif;
        else v -= (otDif+1);

        if (v < 0) {
            v += otDif;
            nd.fst += v;
            nd.snd = arr[i-1]+v;
            break;
        }

        nd.fst = actX;
        nd.snd = arr[i];
    }

    printf("%d %d",nd.fst,nd.snd);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
