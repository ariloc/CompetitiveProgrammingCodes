#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;
ll const INFL = 9e18;

ll dp[MAXN];

long long rara(long long V, long long X) {
    ll cnt = 0;

    if (X > 1e5) {
        ll auxi = max(0LL,V-(ll)1e5) / X; // floor
        cnt += auxi;
        V -= auxi * X;

        if (V > 1e5) {
            auxi = (V-1e5+100)/100;
            cnt += auxi;
            V -= auxi * 100;
        }
    }
    else if (X > 100) {
        // 100 < X <= 1e5
        if (V > 1e5) {
            ll auxi = (V-1e5+X)/X;
            cnt += auxi;
            V -= auxi * X;
        }
    }
    else {
        if (V > 1e5) {
            ll auxi = (V-1e5+100)/100;
            cnt += auxi;
            V -= auxi * 100;
        }
    }
    
    forn(i,MAXN) dp[i] = INFL;
    dp[0] = 0;
    
    vector<ll> coins = {1,2,5,10,25,50,100,X};
    for (auto &c : coins)
        for (ll i = c; i < V+1; i++)
            dp[i] = min(dp[i], dp[i-c]+1);

    return cnt + dp[V];
}
