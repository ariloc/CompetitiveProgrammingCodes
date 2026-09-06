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

ll escalera(vi v, int H) {
    ll steps = 0, acc = 0, highest = 0;
    bool ok = false;
    for (auto &i : v) {
        acc += i;
        steps++;
        if (acc >= H) {
            ok = true;
            break;
        }
        highest = max(highest, acc);
    }
    if (ok) return steps;
    ll k = (max(0LL,H-highest)+acc-1)/acc;
    steps *= k;
    acc *= k;
    for (auto &i : v) {
        acc += i;
        steps++;
        if (acc >= H) {
            ok = true;
            break;
        }
    }
    return steps;
}
