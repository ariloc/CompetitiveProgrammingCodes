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

const int MAXN = 1002;

int arr[MAXN];
map<int,ii> sums;

int main() {
    int n,x; scanf("%d %d",&n,&x);
    forn(i,n) scanf("%d",&arr[i]);

    forn(i,n) {
        forsn(j,i+1,n) {
            int dif = x-arr[i]-arr[j];
            auto it = sums.find(dif);
            if (it != sums.end()) {printf("%d %d %d %d",i+1,j+1,(*it).snd.fst,(*it).snd.snd); return 0;}
        }
        forn(j,i) sums[arr[i]+arr[j]] = {i+1,j+1};
    }
    printf("IMPOSSIBLE");
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
