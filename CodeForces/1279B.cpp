#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

ll binSrch (vector<ll> &s, ll &N, ll &x) {
    ll low = -1;
    ll high = N;

    while (high - low > 1) {
        ll mid =  low + (high-low) / 2;
        if (s[mid] >= x)
            high = mid;
        else low = mid;
    }

    return (high == N or high == N-1 ? -1 : high);
}

int main() {
    FAST_IO;

    int N;
    cin >> N;

    forn (i,N) {
        ll n,s;
        vector<ll> secs;
        cin >> n >> s;
        ll prev = 0;
        forn (j,n) {
            ll x;
            cin >> x;
            secs.push_back(x+prev);
            prev += x;
        }
        ll result = binSrch(secs,n,s);
        //cerr << result << "!!" << endl;
        //cout << result << ' ' << secs[result-1] << ' ' << secs[result+1] << ' ' << secs[result+2] << ' ';
        if (result == -1) cout << 0;
        else {
            ll best = -1, ind = 0;
            forn(k,result+1) {
                if (secs[k]-(k-1 < 0 ? 0 : secs[k-1]) > best) {
                    best = secs[k]-(k-1 < 0 ? 0 : secs[k-1]);
                    ind = k;
                }
            }
            if (secs[result+1] - best <= s)
                cout << ind+1;
            else cout << 0;
        }
        cout << '\n';
    }

    return 0;
}
