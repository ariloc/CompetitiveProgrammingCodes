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

int const MAXN = 1e5+5;
int const INF = 2e9;

int hit[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m; cin >> n >> m;

        forn(i,m+1) hit[i] = 0;

        vector<vi> sets;
        set<int> allseen;
        forn(i,n) {
            int l; cin >> l;
            vi cur;
            set<int> seen;
            forn(j,l) {
                int x; cin >> x;
                if (!seen.count(x)) hit[x]++, seen.insert(x);
                cur.pb(x);
                allseen.insert(x);
            }
            sets.pb(cur);
        }

        if ((int)allseen.size() < m) {
            cout << "NO\n";
            continue;
        }

        int cnt = 0;
        for (auto &i : sets) {
            int mini = INF;
            for (auto &j : i) {
                mini = min(mini, hit[j]);
            }
            if (mini > 1) cnt++;
        }

        if (cnt >= 2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
