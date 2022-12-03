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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 2e5+5;
const int MOD = 998244353;
const int INV = 828542813;

int dp_exp[MAXN], dp_prob[MAXN];

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;   a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    int n,p; scanf("%d %d", &n, &p);
    int prob[2] = {(int)(((100-p) * (ll)INV) % MOD), (int)((p * (ll)INV)%MOD)};

    dp_prob[n+2] = 1;
    dforsn(i,3,n+3) {
        forn(k,2) {
            dp_exp[i-k-1] = sumMod(dp_exp[i-k-1], sumMod((dp_exp[i] * (ll)prob[k])%MOD, (dp_prob[i] * (ll)prob[k])%MOD));
            dp_prob[i-k-1] = sumMod(dp_prob[i-k-1], (dp_prob[i] * (ll)prob[k])%MOD);
        }
    }

    printf("%d", sumMod(dp_exp[2], dp_exp[1]));
    
    return 0;
}


