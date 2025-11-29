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

int aq[MAXN], ar[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        ll k; cin >> k;
        forn(i,n) cin >> aq[i];
        forn(i,n) cin >> ar[i];

        sort(aq,aq+n);

        priority_queue<int,vi,greater<int>> rests;
        forn(i,n) rests.push(ar[i]);
        int op = 0;
        dforn(i,n) {
            int cur = rests.top();
            int y = cur+1;
            if (y > k) continue;
            ll x = y*(ll)aq[i] + cur;
            if (x > k) continue;
            op++;
            rests.pop();
        }

        cout << op << '\n';
    }

    return 0;
}
