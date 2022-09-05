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
typedef long double ld;

const int MAXT = 4;

bool probs[1<<MAXT];

int main() {
    int n,k; scanf("%d %d",&n,&k);

    forn(i,n) {
        int mk = 0;
        forn(j,k) {
            int x; scanf("%d",&x);
            mk |= (x<<j);
        }
        probs[mk] = true;
    }

    bool rta = false;
    forsn(i,1,1<<(1<<k)) {
        int aux = i, ind = 0;
        bool missing = 0;
        int cnt[] = {0,0,0,0};
        int used = 0;
        while (aux) {
            if (aux&1) {
                used++;
                if (!probs[ind]) {
                    missing = 1; break;
                }
                forn(j,k)
                    if (ind&(1<<j)) cnt[j]++;
            }
            aux >>= 1; ind++;
        }

        if (missing) continue;

        //cerr << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << used << ' ' << i << endl;

        bool tmp_rta = true;
        forn(j,4)
            if (cnt[j] > used/2)
                tmp_rta = false;

        if (tmp_rta) {
            rta = true; break;
        }
    }

    printf("%s",rta ? "YES" : "NO");

    return 0;
}
