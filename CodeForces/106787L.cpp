#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXS = 43046721;
int const MAXN = 16;
int const INF = 2e9;

int w[MAXN];
int dp[MAXS];
ii sum[MAXS];

int pot3(int x) {
    int r = 1;
    while (x--) r *= 3;
    return r;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> w[i];

    int stat = pot3(n);
    int rta = INF;
    forsn(mk,1,stat) {
        dp[mk] = INF;
        int pot = 1, cmk = mk;
        bool zero = false;
        forn(i,n) {
            int bit = cmk%3;
            if (bit) {
                int auxi = mk-pot*bit;
                auto [l1,l2] = sum[auxi];
                if (bit == 1) l1 += w[i]; else l2 += w[i];
                sum[mk] = {l1,l2};
                dp[mk] = min(dp[mk],max(dp[auxi],abs(l1-l2)));
            }
            else zero = true;
            pot *= 3;
            cmk /= 3;
        }
        if (!zero) rta = min(rta,dp[mk]);
    }

    cout << rta << '\n';

    return 0;
}
