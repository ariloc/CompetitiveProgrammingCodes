#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXF = 15;
const int INF = 2e9;

ll fact[MAXF];

int main() {
    fact[0] = 1;
    forsn(i,1,MAXF) fact[i] = fact[i-1] * (ll)(i+1);

    int t; scanf("%d",&t);
    forn(o,t) {
        ll x; scanf("%lld",&x);

        int mini = INF;
        forn(j,1<<MAXF) {
            ll val = x;
            int aux = j, cnt = 0;
            while (aux) {
                int bit = aux & -aux;
                val -= fact[31-__builtin_clz(bit)];
                aux -= bit, cnt++;
            }

            mini = min(mini,cnt + __builtin_popcountll(val));
        }

        printf("%d\n",mini);
    }

    return 0;
}