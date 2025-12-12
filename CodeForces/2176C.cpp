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
int const INF = 2e9;

int arr[MAXN];
ll rta[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];

        forn(i,n) rta[i] = 0;

        sort(arr,arr+n);

        int maxi = 0;
        forn(i,n) if (arr[i]&1) maxi = max(maxi,arr[i]);
    
        if (!maxi) {
            forn(i,n) cout << "0 ";
            cout << '\n';
            continue;
        }

        rta[0] = maxi;

        ll s = 0;
        int cnt = 0;
        dforn(i,n) {
            if (!(arr[i]&1)) {
                s += arr[i];
                cnt++;
                rta[cnt] = maxi+s;
            }
        }

        for (int i = cnt+2; i < n; i += 2)
            rta[i] = maxi+s;

        int mini = INF;
        forn(i,n) if (!(arr[i]&1)) mini = min(mini,arr[i]);

        if (mini < INF) {
            int i;
            for (i = cnt+1; i < n-1; i += 2)
                rta[i] = maxi+s-mini;
            if (i == n-3) {
                rta[n-1] = 0;
            }
        }
        
        forn(i,n) cout << rta[i] << ' ';
        cout << '\n';
    }

    return 0;
}
