#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int const MAXN = 305;
int const MAXI = 605;
int const MOD = 1e9+7;

int dp[MAXI][MAXN];
ii rang[MAXN];
int cntf[MAXI], cnti[MAXI];
vi pts;
int fact[MAXN],invfact[MAXN];

int binExp(int a, int k) {
    int r = 1;
    while(k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD, k /= 2;
    }
    return r;
}

int main() {
    FAST_IO;

    fact[0] = 1, invfact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1] * (ll)i)%MOD;
    forsn(i,1,MAXN) invfact[i] = binExp(fact[i], MOD-2);
    
    int n; cin >> n;
    forn(i,n) {
        cin >> rang[i].fst >> rang[i].snd;
        rang[i].fst--; // separators
    }

    forn(i,n-1) {
        rang[i+1].fst = max(rang[i].fst+1,rang[i+1].fst);
        rang[i].snd = min(rang[i+1].snd-1,rang[i].snd);
    }

    forn(i,n) pts.pb(rang[i].fst), pts.pb(rang[i].snd);
    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());

    forsn(i,1,sz(pts)) {
        forn(j,n) if (rang[j].fst <= pts[i-1]) cnti[i]++;
        forn(j,n) if (rang[j].snd <= pts[i]) cntf[i]++;
    }

    dp[0][0] = 1;
    forsn(i,1,sz(pts)) {
        vi nums;
        int dif = pts[i]-pts[i-1];
        int val = 1;
        forn(j,MAXN) {
            val = (val * (ll)max(1,(dif-j)))%MOD;
            nums.pb(val);
        }
        
        forsn(j,cntf[i],cnti[i]+1) {
            forn(k,j+1) { // nCk(dif,j-k)
                if (j-k > dif) continue;
                dp[i][j] = (dp[i][j] + ((dp[i-1][k] * (ll)(((j-k-1 >= 0 ? nums[j-k-1] : 1)*(ll)invfact[j-k])%MOD))%MOD))%MOD;
            }
        }
    }

    cout << dp[sz(pts)-1][n] << '\n';

    return 0;
}
