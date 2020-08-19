#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e6+2;
const int MAXM = 5e4+5;

ii frag[MAXN];
bitset<MAXM> mark;

int main() {
    freopen("polimorfo.in","r",stdin);
    freopen("polimorfo.out","w",stdout);

    int N,M; scanf("%d %d",&N,&M);

    int sz = 0;
    forn (i,N) {
        int x; scanf("%d",&x);
        if (x > M or x < 1) continue;
        frag[sz++] = {x,i+1};
    }

    if (!sz) {puts("0"); return 0;}

    //two pointers
    vi appear;
    int r = 0;
    forn (i,sz) {
        while (r < sz and !mark[frag[r].fst] and r-i < M and (frag[r].snd-frag[i].snd) == (r-i)) {
            mark[frag[r++].fst] = true;
        }

        if (r-i == M) appear.pb(frag[i].snd);
        mark[frag[i].fst] = false;
        if (r == i) r++;
    }

    printf("%d\n",appear.size());
    if ((int)appear.size() <= 10) for (auto &i : appear) printf("%d ",i);
    else {
        forn (i,5) printf("%d ",appear[i]);
        forsn (i,appear.size()-5,appear.size()) printf("%d ",appear[i]);
    }

    return 0;
}
