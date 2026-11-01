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

int bowling1(int R, vector<int> &x, vector<int> &y) {
    int n = sz(x);
    vi cnt(4,0);
    forn(i,n) if (y[i] > 0 && -R <= x[i] && x[i] <= R) cnt[0]++;
    forn(i,n) if (y[i] < 0 && -R <= x[i] && x[i] <= R) cnt[1]++;
    forn(i,n) if (x[i] < 0 && -R <= y[i] && y[i] <= R) cnt[2]++;
    forn(i,n) if (x[i] > 0 && -R <= y[i] && y[i] <= R) cnt[3]++;
    int maxi = 0;
    forn(k,4) maxi = max(maxi,cnt[k]);
    return maxi;
}
