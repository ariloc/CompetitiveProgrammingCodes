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
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int main() {
    FAST_IO;

    priority_queue<ii,vector<ii>,greater<ii>> Q;
    vector<ii> neg;

    int n,r; cin >> n >> r;
    forn(i,n) {
        int a,b; cin >> a >> b;
        if (b >= 0) Q.push({a,b});
        else neg.pb({a,b});
    }

    while (!Q.empty() && Q.top().fst <= r) {
        auto e = Q.top(); Q.pop();
        r += e.snd;
    }

    if (!Q.empty()) return cout << "NO\n", 0;

    sort(all(neg),[](const ii &lhs, const ii &rhs){
        return lhs.fst+lhs.snd > rhs.fst+rhs.snd;
    });

    for (auto &i : neg) {
        if (i.fst > r) return cout << "NO\n", 0;
        r += i.snd;
        if (r < 0) return cout << "NO\n", 0;
    }

    cout << "YES\n";

    return 0;
}
