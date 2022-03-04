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

const int INF = 2e9;
const int MAXN = 2e5+5;

int arr[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d",&arr[i]);

        bool isZ = 0;
        forn(i,n) if (!arr[i]) isZ = 1;

        if (!isZ) {
            printf("%d\n",n);
            forn(i,n) printf("0 ");
            puts("");
            continue;
        }

        multiset<int> mems;
        forn(i,n) mems.insert(arr[i]);
        vi histo(n+5,0), b;

        int mex = 0;
        forn(i,n) {
            histo[arr[i]]++;
            mems.erase(mems.find(arr[i]));

            while (histo[mex]) mex++;

            if (!mems.count(mex)) {
                b.pb(mex);
                forn(j,mex) histo[j] = 0;
                mex = 0;
            }
        }

        printf("%d\n",(int)b.size());
        for (auto &i : b) printf("%d ",i);
        puts("");
    }

    return 0;
}
