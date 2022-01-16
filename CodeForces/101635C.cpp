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

const int MOD = 1e9;
const int MAXK = 8;
const int NEUT = 0;

typedef vector<ll> vll;
struct mat {
    vector<vll> M;
    mat() {};
    mat(int n, int m) : M(n,vll(m,NEUT)) {};
    vll &operator[] (int x) {return M[x];}
    const vll &operator[] (int x) const {return M[x];}
    int size() const {return (int)M.size();}
};

mat operator* (mat A, mat B) {
    int n = A.size(), m = (int)B[0].size(), o = (int)A[0].size();
    mat R(n,m);
    forn(i,R.size()) forn(j,R[0].size()) R[i][j] = NEUT;

    forn(i,n) forn(j,m) forn(k,o)
        R[i][j] = (R[i][j] + ((A[i][k] * B[k][j])%MOD))%MOD;
    return R;
}

mat matExp (mat A, ll k) {
    mat R = mat(A.size(),(int)A[0].size());
    bool blank = true;
    while (k) {
        if (k&1) {
            if (blank) blank = false, R = A;
            else R = (R*A);
        }
        A = (A*A); k >>= 1;
    }
    return R;
}

int dp[2][1<<MAXK];
ll n,m;
mat T;

void solve (int col, int bit, int mk, int nxt_mk, bool reg = false) {
    if (bit >= n) {
        dp[col+1][nxt_mk] = (dp[col+1][nxt_mk] + dp[col][mk])%MOD;
        if (reg) T[mk][nxt_mk] = (T[mk][nxt_mk] + dp[col][mk])%MOD;
        return;
    }
    solve(col,bit+1,mk,nxt_mk,reg);
    if (!(mk&(1<<bit))) {
        solve(col,bit+1,mk,nxt_mk|(1<<bit),reg);
        if (bit+1 < n && !(mk & (1<<(bit+1)))) 
            solve(col,bit+2,mk,nxt_mk,reg);
    }
}

int main() {
    scanf("%lld %lld",&n,&m);

    T = mat(1<<n, 1<<n);

    forn(i,1<<n) dp[0][i] = 1;
    forn(j,1<<n) solve(0,0,j,0,true);

    T = matExp(T,m);

    printf("%d",(int)T[0][0]);

    return 0;
}