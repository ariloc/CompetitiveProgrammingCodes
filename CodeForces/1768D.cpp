#include <bits/stdc++.h>
#include <queue>

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

int arr[MAXN];
bitset<MAXN> done;

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d",&arr[i]);
        forn(i,n) done[i] = 0;

        int cnt = 0;
        bool flag = 0;
        forn(i,n) {
            if (done[i]) continue;
            cnt++;
            if (arr[i]-1 == i) continue;
            int cur = i;
            vi here;
            while (!done[cur]) {
                done[cur] = true;
                here.pb(arr[cur]);
                cur = arr[cur]-1;
            }
            sort(all(here));
            forn(j,here.size()-1) {
                if (here[j+1] == here[j]+1) flag = 1;
            }
        }

        printf("%d\n",n-cnt+(flag ? -1 : 1));
    }
       
    return 0;
}
