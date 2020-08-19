#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9+2;
const int MAXO = 252;

ii oficinas[MAXO];
ii dp[MAXO][MAXO]; // [nodo]
int sumT[MAXO][MAXO];
string rta;

char tmp[7];
int show (int l, int r, int lvl) {
    int mid = dp[l][r].snd;
    if (mid == -1)
        return 0;

    rta += '(';
    int rA = show(l,mid,lvl+1);

    sprintf(tmp,"%d",oficinas[mid].fst);
    rta += tmp;

    int rB = show(mid+1,r,lvl+1);
    rta += ')';

    return rA + rB + oficinas[mid].snd*lvl;
}

int solve (int l, int r) {
    if (dp[l][r].fst != -1) return dp[l][r].fst;
    if (l == r) return 0;
    if ((r-l) < 2)
        if (l != r) {
            sumT[l][r] = oficinas[l].snd;
            dp[l][r] = {oficinas[l].snd,l};
            return dp[l][r].fst;
        } else return 0;
    int best = INF, sumB = INF, ind = -1;
    forsn (mid,l,r) {
        // [l,mid) (excluyo nodo elegido, mid)
        // [mid+1,r) (excluyo nodo previo elegido, r)
        int sum = solve(l,mid)+solve(mid+1,r);
        int calc = sumT[l][mid] + sumT[mid+1][r];

        if (calc < best) {
            sumB = sum;
            best = calc;
            ind = mid;
        }
    }
    //if (ind == -1) {dp[l][r] = {0,-1}; return 0;}
    int calcMe = oficinas[ind].snd+sumB;
    sumT[l][r] = best+calcMe;
    dp[l][r] = {calcMe,ind};
    return dp[l][r].fst;
}

int main() {
    //freopen("oficinas.in","r",stdin);
    //freopen("oficinas.out","w",stdout);

    memset(dp,-1,sizeof(dp));

    int N;
    scanf("%d",&N);

    forn(i,N) {
        int x,f;
        scanf("%d %d",&x,&f);
        oficinas[i] = {x,f};
    }

    sort(oficinas,oficinas+N);
    solve(0,N);

    printf("%d\n",show(0,N,1));
    printf("%s",rta.c_str());

    return 0;
}
