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

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,k; cin >> n >> k;
        forn(i,n) cin >> arr[i];

        sort(arr,arr+n);
        set<int> seen;
        forn(i,n) seen.insert(arr[i]);

        bool yes = true;
        forn(i,n) {
            for (int j = arr[i]+arr[i]; j <= k; j += arr[i])
                if (!seen.count(j)) {
                    yes = false; break;
                }
            if (!yes) break;
        }

        if (!yes) {
            cout << "-1\n";
            continue;
        }

        set<int> toDel, rta;
        forn(i,n) {
            if (toDel.count(arr[i])) continue;
            rta.insert(arr[i]);
            for (int j = arr[i]+arr[i]; j <= k; j += arr[i])
                toDel.insert(j);
        }

        cout << (int)rta.size() << '\n';
        for (auto &i : rta) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
