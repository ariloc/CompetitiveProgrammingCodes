#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

vector<ll> cap;

// v/p >= D
// v >= d*p

long long thor(vector<int> &a, vector<int> &f, vector<int> &p, int D) {
    forn(i,a.size()) cap.pb((ll)a[i]*f[i]);
    sort(all(cap));
    ll comb = 0;
    forn(i,p.size())
        comb += (int)cap.size()-(int)(lower_bound(all(cap),(ll)D*p[i]) - cap.begin());
    return comb;
}
