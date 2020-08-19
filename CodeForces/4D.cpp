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
 
const int MAXN = 5005;
 
struct env {
    int w,h,id;
 
    bool operator< (const env &o) const{
        if (o.w == w) return o.h > h;
 
        return o.w > w;
    }
};
 
env sobres[MAXN]; int ind = 0;
int dp[MAXN], P[MAXN];
 
int main() {
    FAST_IO;
 
    forn (i,MAXN) {dp[i] = 1; P[i] = -1;}
    int n,w,h; cin >> n >> w >> h;
 
    forn (i,n) {
        int W,H; cin >> W >> H;
        if (W <= w or H <= h) continue;
        sobres[ind++] = {W,H,i+1};
    }
 
    sort(sobres,sobres+ind);
 
    forn (i,ind) {
        forsn (j,i+1,ind) {
            if (sobres[i].w < sobres[j].w and sobres[i].h < sobres[j].h)
                if (dp[i]+1 > dp[j]) {
                    dp[j] = dp[i]+1;
                    P[j] = i;
                }
        }
    }
    int maxi = -1, myInd = -1;
    forn (i,ind) {
        if (dp[i] > maxi) {
            maxi = dp[i];
            myInd = i;
        }
    }
 
    if (maxi == -1) {cout << 0; return 0;}
 
    vi used;
    for (int i = myInd; i != -1; i = P[i])
        used.pb(sobres[i].id);
 
    cout << maxi << '\n';
    dforn(i,used.size()) cout << used[i] << ' ';
 
    return 0;
}
 
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!