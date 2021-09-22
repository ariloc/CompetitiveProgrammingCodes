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

const int MAXN = 3e5+2;
const int MAXM = 1e6+2;

ll FT[MAXN];
int arr[MAXN];
int divisor[MAXM];
set<int> posib;

ll getFT (int v) {
    ll r = 0;
    for (int i = v; i; i -= i & -i)
        r += FT[i];
    return r;
}

void setFT(int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

void criba (int N) {
    forsn (i,1,N+1)
        for (int j = i; j <= N; j+=i)
            divisor[j]++;
}

int main() {
    criba(MAXM-1);

    int n,m; scanf("%d %d",&n,&m);

    forn (i,n) {
        scanf("%d",&arr[i+1]);
        setFT(i+1,arr[i+1]);
        if (arr[i+1] > 2) posib.insert(i+1);
    }

    forn (i,m) {
        int typ,l,r; scanf("%d %d %d",&typ, &l, &r);
        if (typ == 1) {
            auto it = posib.lower_bound(l);
            while (it != posib.end() and *it <= r) {
                int ind = *it;
                setFT(ind,divisor[arr[ind]]-arr[ind]);
                arr[ind] = divisor[arr[ind]];
                it++; if (arr[ind] <= 2) posib.erase(prev(it));
            }
        }
        else {
            printf("%lld\n",getFT(r)-(l-1 <= 0 ? 0 : getFT(l-1)));
        }
    }

    return 0;
}