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

int main() {
    freopen("toneles.in","r",stdin);
    freopen("toneles.out","w",stdout);

    int L,N; scanf("%d %d",&L,&N);

    ll accum = 0, r = 0;
    int l = -1, cD = 1;
    forn (i,N) {
        int x; scanf("%d",&x);
        if (l == -1 and x) l = i;
        accum += x;
        if (accum > L*cD)
            {r += (N-l); l = i; cD++;}
    }
    r += (N-l);

    printf("%lld\n%d",r,l+1);

    return 0;
}
