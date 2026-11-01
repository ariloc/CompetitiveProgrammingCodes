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

vector<int> dhondt(int n, vector<int> &v) {
    vi rta(sz(v),0),divs(sz(v),1);
    int total = accumulate(all(v),0);
    forn(i,n) {
        pair<ld,int> maxi = {0,-1};
        forn(j,sz(v)) {
            if (100*v[j] < 3 * total) continue;
            maxi = max(maxi,{v[j]/(ld)divs[j],j});
        }
        divs[maxi.snd]++;
        rta[maxi.snd]++;
    }
    return rta;
}
