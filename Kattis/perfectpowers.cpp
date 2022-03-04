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

const ll INF = 1e10;
const int MAXN = 40;
const int MAXB = 70000;

vector<ll> pows[MAXN];

int main() {
    FAST_IO;

    ll x;

    forsn(i,2,MAXB)
        for (ll v = (ll)i*i, p = 2; v < INF; v *= (ll)i, p++)
            pows[p].pb(v);

    while (cin >> x) {
        if (!x) break;
        
        bool neg = false;
        if (x < 0) neg = true, x = -x;

        int maxi = 1;
        forsn(i,2,MAXN) 
            if (!neg || i&1)
                if (binary_search(all(pows[i]),x))
                    maxi = max(maxi,i);

        cout << maxi << endl;
    }

    return 0;
}