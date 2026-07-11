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

int const INF = 1e9;

vector<int> erupcion(vector<int> &r) {
    vi rta;
    int last = 0;
    int n = sz(r);
    forn(i,n) {
        int mini = INF;
        forn(j,n) if (r[j] > last) mini = min(mini,r[j]);
        last = mini;
        int cnt = 0;
        forn(j,n) {
            if (r[j] > last && (!j || r[j-1] <= last))
                cnt++;
        }
        rta.pb(cnt);
    }
    return rta;
}
