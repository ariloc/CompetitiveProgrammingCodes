#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

vi nums;
vector<ii> pows;

int main() {
    FAST_IO;

    ll prvSum = 0;
    forn(i,30) nums.pb(1<<i), prvSum += 1<<i;
    forn(i,35) { // add building of powers
        int nUsed = 2*(i+1) + 1;
        pows.pb({(1<<29) - nUsed, nUsed});
        prvSum += 1<<29;
    }
    
    int t; cin >> t;
    forn(o,t) {
        vi added;
        int n; cin >> n;
        for (auto &i : nums) cout << i << ' ';
        for (auto &i : pows) cout << i.fst << ' ' << i.snd << ' ';
        cout << endl;

        ll s = prvSum;
        forn(i,n) {int x; cin >> x; added.pb(x); s += x;}
        for (auto &i : nums) added.pb(i);
        for (auto &i : pows) added.pb(i.fst), added.pb(i.snd);

        
        sort(all(added));
        ll acc0 = 0, acc1 = 0;
        set<int> a,b;
        dforn(i,added.size()) {
            if (a.empty()) a.insert(added[i]), acc0 += added[i];
            else if (b.empty()) b.insert(added[i]), acc1 += added[i];
            else if (acc0 < acc1) a.insert(added[i]), acc0 += added[i];
            else b.insert(added[i]), acc1 += added[i];
        }

        for (auto &i : a) cout << i << ' ';
        cout << endl;
    }
    
    return 0;
}
