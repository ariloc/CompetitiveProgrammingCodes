#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 4005;
int const MOD = 998244353;

int FT[2][MAXN];

void setFT(int p, int v, int *ft) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        ft[i] = (ft[i]+v)%MOD;
}

int getFT(int p, int *ft) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r = (r + ft[i])%MOD;
    return r;
}

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    int t = min(n,k);
    forsn(i,1,k+1) setFT(i,1,FT[1]);
    forsn(i,2,t+1) {
        forn(j,MAXN) FT[i%2][j] = 0;
        forsn(j,1,k+1) {
            int l = ((i*j-k)+(i-2))/(i-1);
            int r = (i*j - 1) / (i-1);
            int v = (getFT(r,FT[1-i%2]) - getFT(max(1,l)-1,FT[1-i%2]) + MOD)%MOD;
            setFT(j,v,FT[i%2]);
        }
    }

    cout << getFT(MAXN-1,FT[t%2]) << '\n';

    return 0;
}
