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

const int MAXN = 1e6;

int FT[3][MAXN];

void setFT (int k, int p, int v){
    for (int i = p; i < MAXN; i += i & -i)
        FT[k][i] += v;
}

int getFT (int k, int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[k][i];
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        string s; cin >> s;

        forn(i, 2*n+4) forn(k,3) FT[k][i] = 0;
        setFT(0,n+2,1);

        int sum = 0, cnt = 0;
        ll rta = 0;
        forn(i,n) {
            if (s[i] == '-') sum++, cnt++;
            else sum--, cnt = 0;

            int rest = ((sum%3) + 3)%3;
            rta += getFT(rest, sum + n+2);

            setFT(rest, sum + n+2, 1);
        }

        printf("%lld\n", rta);
    }
            
    return 0;
}

