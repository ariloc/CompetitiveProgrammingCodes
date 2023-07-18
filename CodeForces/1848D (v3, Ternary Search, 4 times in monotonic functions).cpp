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

int s,k;

ll newbonus (int m) {
    ll news = s;
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

        if ((s%10) == 0) {
            printf("%lld\n",s*(ll)k);
            continue;
        }
        if ((s%10) == 5) {
            printf("%lld\n",max((ll)s*k, (s+5)*(ll)(k-1)));
            continue;
        }

        ll maxi = s*(ll)k;
        if (s&1) {
            s += s%10, --k;
        }
    
        // search for each parabola defined by each remainder in the period
        forn(rest,4) {
            int low = 0, high = k/4;
            while (high-low > 1) {
                int mid = (high+low)/2;

                if (calc(4*mid+rest) <= calc(4*(mid+1)+rest)) low = mid;
                else high = mid;
            }
            forsn(i,max(0,low-2),min(k+1,low+2)) maxi = max(maxi,calc(4*i+rest));
        }

        printf("%lld\n",maxi);
    }

    return 0;
}
