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

int const MAXN = 2e5+5;

int val[MAXN];

int query(int i) {
    if (val[i] != -1) return val[i];
    cout << "? " << i+1 << endl;
    char c; cin >> c;
    return val[i] = (c == 'R' ? 1 : 0);
}

int main() {
    FAST_IO;

    fill(val,val+MAXN,-1);

    int n; cin >> n;

    if (query(0) == query(n-1)) return cout << "! " << n << endl, 0;

    int l = 0, r = n;
    while (r-l > 1) {
        int mid = (l+r)/2;
        int co1 = query(l), co2 = query(mid);
        if (((mid-l+1) % 2 && co1 != co2) || (!((mid-l+1) % 2) && co1 == co2))
            r = mid;
        else l = mid;
    }

    cout << "! " << l+1 << endl;

    return 0;
}
