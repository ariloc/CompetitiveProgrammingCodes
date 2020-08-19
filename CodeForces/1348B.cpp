#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 102;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n,k; cin >> n >> k;

        bitset<MAXN> done;
        done.reset();
        int cnt = 0;
        vi variety;
        forn (j,n) {
            int x; cin >> x;
            if (!done[x]) {done[x] = true; cnt++; variety.pb(x);}
        }

        if (cnt > k) {cout << "-1\n"; continue;}
        else {
            cout << n*k << '\n';
            forn (j,n) forn (l,k) cout << variety[min(l,(int)variety.size()-1)] << ' ';
            cout << '\n';
        }
    }

    return 0;
}