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

int const MAXN = 1e6+5;

int arr[MAXN],s[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,d; cin >> n >> d;
        forn(i,n) cin >> arr[i];
        forn(i,n) s[i] = -1;

        queue<int> Q;
        forn(i,n) if (!arr[i]) Q.push(i), s[i] = 0;
        while (!Q.empty()) {
            auto e = Q.front(); Q.pop();

            if (s[(e+d)%n] == -1) {
                s[(e+d)%n] = s[e]+1;
                Q.push((e+d)%n);
            }
        }
        int maxi = 0;
        bool posib = true;
        forn(i,n) {
            if (s[i] == -1) posib = false;
            maxi = max(maxi,s[i]);
        }

        cout << (posib ? maxi : -1) << '\n';
    }

    return 0;
}
