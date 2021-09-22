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

const int MAXN = 2e5+2;

map<int,set<ll> > col;
ll L[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) cin >> L[i];

    forn (j,2)
        forn (i,N) {
            int a; cin >> a;
            col[a].insert(L[i]);
        }

    int K; cin >> K;
    forn (i,K) {
        int x; cin >> x;
        auto it = col[x].lower_bound(0);
        if (it == col[x].end()) {cout << -1 << ' '; continue;}
        else cout << *it << ' ';

        ll el = *it;
        col[1].erase(el);
        col[2].erase(el);
        col[3].erase(el);
    }

    return 0;
}