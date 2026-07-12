#include <vector>

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
typedef vector<ll> vll;

bool can(ll mid, vll ciud, vll pe) {
    ll need = 0;
    forn(i,sz(ciud)) {
        if (ciud[i] > mid) {
            ll contrib = min(need,ciud[i]-mid);
            need -= contrib;
            ciud[i] -= contrib;
            if (i < sz(pe) && ciud[i] > mid+pe[i])
                ciud[i+1] += ciud[i]-mid-pe[i];
        }
        else {
            need += mid - ciud[i];
        }
        if (need && i < sz(pe)) need += pe[i];
    }

    return need == 0;
}

int panes(vector<int> &ciudades, vector<int> &peajes) {
    int n = sz(ciudades);
    ll sum = 0;
    forn(i,n) sum += ciudades[i];

    vector<ll> ciud, pe;
    for (auto &i : ciudades) ciud.pb(i);
    for (auto &i : peajes) pe.pb(i);

    ll lo = 0, hi = sum+1;
    while (hi - lo > 1) {
        ll mid = (hi+lo)/2;
        if (can(mid,ciud,pe)) lo = mid;
        else hi = mid;
    }

    return lo;
}
