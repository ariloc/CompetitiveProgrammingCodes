#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int main() {
    int t; scanf("%d",&t);

    forn(o,t) {
        int x; scanf("%d",&x);
        ll cnt = 0;
        forsn(i,1,x+1) forsn(j,i,x+1) {
            if (__gcd(x,i)*__gcd(x,j) == __gcd(i*j,x)) cnt++;
        }
        printf("%lld\n",cnt);
    }

    return 0;
}