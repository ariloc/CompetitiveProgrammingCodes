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

int FTcol[MAXN][MAXN], FTrow[MAXN][MAXN];
int arr[MAXN];

int summod(int a, int b) {
    int x = a+b;
    if (x >= MOD) x -= MOD;
    return x;
}

void setFT(int p, int v, int *FT) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] = summod(FT[i],v);
}

int getFT(int p, int *FT) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r = summod(r,FT[i]);
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];

        forn(i,n+5) forn(j,n+5) FTrow[i][j] = FTcol[i][j] = 0;

        setFT(0,1,FTrow[0]);
        setFT(0,1,FTcol[0]);

        forn(i,n) {
            forn(k,arr[i]+1) {
                int v = getFT(arr[i],FTcol[k]);
                setFT(arr[i],v,FTcol[k]);
                setFT(k,v,FTrow[arr[i]]);
            }
            forsn(j,arr[i]+1,n+1) {
                int v = getFT(arr[i],FTrow[j]);
                setFT(arr[i],v,FTrow[j]);
                setFT(j,v,FTcol[arr[i]]);
            }
        }

        int s = 0;
        forn(i,n+1) s = summod(s,getFT(n,FTrow[i]));
        cout << s << '\n';
   }

    return 0;
}
