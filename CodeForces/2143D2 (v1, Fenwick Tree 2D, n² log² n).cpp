#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2005;
int const MOD = 1e9+7;

int FT[MAXN][MAXN];
int arr[MAXN];

void setFT(int y, int x, int v) {
    v = (v+MOD)%MOD;
    x += 2; y += 2;
    for (int i = y; i < MAXN; i += i & -i)
        for (int j = x; j < MAXN; j += j & -j)
            FT[i][j] = (FT[i][j]+v)%MOD;
}

int getFT(int y, int x) {
    x += 2; y += 2;
    int r = 0;
    for (int i = y; i; i -= i & -i)
        for (int j = x; j; j -= j & -j)
            r = (r+FT[i][j])%MOD;
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        
        forn(i,n) cin >> arr[i];

        forn(i,n+5) forn(j,n+5) FT[i][j] = 0;
        setFT(0,0,1);

        forn(i,n) {
            forn(k,arr[i]+1) {
                int v = getFT(arr[i],k) - getFT(arr[i],k-1);
                setFT(arr[i],k,v);
            }
            forsn(j,arr[i]+1,n+1) {
                int v = getFT(j,arr[i]) - getFT(j-1,arr[i]);
                setFT(j,arr[i],v);
            }
        }

        cout << getFT(n,n) << '\n';
    }

    return 0;
}
