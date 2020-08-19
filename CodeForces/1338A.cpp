#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9+2;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int N; cin >> N;

        ll prev = -INF,maxi = 0;
        forn (j,N) {
            ll x; cin >> x;

            if (j)
                if (x < prev) {maxi = max(maxi,abs(prev-x)); x = prev;}
            prev = x;
        }
        cout << (ceil(log2(maxi+1))) << '\n';
    }

    return 0;
}