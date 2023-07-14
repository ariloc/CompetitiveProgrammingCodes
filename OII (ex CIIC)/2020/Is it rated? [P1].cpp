#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = s; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i--)
#define push_back pb
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 1005;
const int MAXD = 2005;
const int INF = 1e9+5;

struct prob {
    int p,f,t;

    bool operator< (const prob &o) const{
        return (double)f/t > (double)o.f/o.t;
    }
};

prob problems[MAXN];
ll dp[MAXD];
int n,T;

int main() {
    FAST_IO;

    cin >> n >> T;

    forn(i,n) {
        int p,f,tim; cin >> p >> f >> tim;
        problems[i] = {p,f,tim};
    }
    sort(problems,problems+n);

    forn(i,n)
        dforsn(j,problems[i].t,T+1)
            dp[j] = max(dp[j],dp[j-problems[i].t]+max(0LL,(ll)problems[i].p-problems[i].f*(ll)j));

    ll maxi = 0;
    forn(t,T+1) maxi = max(maxi,dp[t]);

    cout << maxi;

    return 0;
}
