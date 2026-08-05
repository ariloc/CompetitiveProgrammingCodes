#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 105;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i+1];

        vi params;
        forn(i,n) 
            params.pb(arr[i]-1), params.pb(arr[i]+1);

        int val = -1;
        for (auto &p : params) {
            vi auxi(n+2);
            bool ok = true;
            forn(i,n) {
                if (arr[i+1] < p) auxi[i]++;
                if (arr[i+1] > p) auxi[i+2]++;
                if (arr[i+1] ==p) ok = false;
            }
            forn(i,n) if (auxi[i+1] != 1) ok = false;
            if (ok) val = p;
        }

        if (val != -1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
