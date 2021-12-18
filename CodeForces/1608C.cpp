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

const int MAXN = 1e5+5;

ii arr[2][MAXN];
int id[2][MAXN];
bool canWin[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n; scanf("%d",&n);
        forn(i,n) canWin[i] = 0;
        forn(i,n) scanf("%d",&arr[0][i].fst), arr[0][i].snd = i;
        forn(i,n) scanf("%d",&arr[1][i].fst), arr[1][i].snd = i;

        sort(arr[0],arr[0]+n);
        sort(arr[1],arr[1]+n);

        forn(i,n) id[0][arr[0][i].snd] = i, id[1][arr[1][i].snd] = i;

        int act[] = {n,n}, tg[] = {n-1,n-1};
        int ind = 0;
        while (act[0] > tg[0] || act[1] > tg[1]) {
            while (act[ind] > tg[ind]) {
                auto aux = arr[ind][--act[ind]];
                canWin[aux.snd] = true;
                tg[1^ind] = min(tg[1^ind],id[1^ind][aux.snd]);
            }
            ind ^= 1;
        }

        forn(i,n) printf("%d",(canWin[i]));
        puts("");
    }
    
    return 0;
}