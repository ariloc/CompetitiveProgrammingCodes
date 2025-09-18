#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;

int val[MAXN], vo[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,k; cin >> n >> k;
        forn(i,n) cin >> val[i];
        forn(i,k) cin >> vo[i];

        sort(vo,vo+k);
        sort(val,val+n);

        ll tot = 0;
        forn(i,n) tot += val[i];

        int idx = n-1;
        forn(i,k) {
            if (idx-vo[i]+1 < 0)
                break;
            tot -= val[idx-vo[i]+1];
            idx -= vo[i];
        }

        cout << tot << '\n';
    }

    return 0;
}
