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

const int MAXN = 5e5+5;

int arr[MAXN],n,m;
ii arr2[MAXN];
bool stroke[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        scanf("%d %d",&n,&m);
        forn(i,n) scanf("%d",&arr[i]);

        forn(i,n) stroke[i] = 0;

        forn(i,n) arr2[i].fst = arr[i], arr2[i].snd = i;
        sort(arr2,arr2+n);

        int acc = m, cnt = 0;
        forn(i,n) {
            if (acc - arr2[i].fst >= 0) acc -= arr2[i].fst, cnt++, stroke[arr2[i].snd] = true;
            else break;
        }

        if (cnt == 0) {
            printf("%d\n",n+1); continue;
        }

        int pos = n+1-cnt;

        if (pos == 1) {
            printf("1\n"); continue;
        }

        if (stroke[cnt]) pos--;
        else {
            if (acc + arr2[cnt-1].fst - arr[cnt] >= 0) pos--;
        }

        printf("%d\n",pos);
    }
   
    return 0;
}
