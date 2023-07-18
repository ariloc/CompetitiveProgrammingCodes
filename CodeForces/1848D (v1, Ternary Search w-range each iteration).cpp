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

ll const INF = 9e18;

int s,k;

ll newbonus (int m) {
    ll news = s;
    if (!m) return news;

    ll rest = news%10;
    if (!rest) return news;
    if (rest == 5) return news+5;

    while ((news%10) != 2 && m) news += (news%10), --m;
    news += (m/4LL) * 20LL; m %= 4;
    while (m) news += (news%10), --m;
    return news;
}

ll calc (int m) {
    return newbonus(m) * (ll)(k-m);
}

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        scanf("%d %d",&s,&k);
        
        int low = -1, high = k;
        while (high-low > 1) {
            int mid = (high+low)/2;

            ll maxi = -INF; int ind = -1;
            forsn(i,max(0,mid-4),min(k,mid+4)) {
                ll aux = calc(i);
                if (aux > maxi) maxi = aux, ind = i;
            }
            if (ind >= mid) low = mid;
            else high = mid;
        }

        ll maxi = -INF;
        forn(i,10) maxi = max(maxi,calc(i));
        forsn(i,max(0,low-4),min(k,low+4))
            maxi = max(maxi,calc(i));

        printf("%lld\n",maxi);
    }

    return 0;
}
