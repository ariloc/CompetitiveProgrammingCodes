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

const int MAXN = 1e5+2;

bitset<MAXN> greedy;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n; cin >> n;

        int improve = -1;
        forn (j,n) {
            int x; cin >> x;

            bool done = false;
            forn (k,x) {
                int g; cin >> g;

                if (!greedy[g] and !done) {
                    greedy[g] = true;
                    done = true;
                }
            }
            if (!done) improve = j+1;
        }
        if (improve == -1) cout << "OPTIMAL\n";
        else {
            forsn (j,1,n+1)
                if (!greedy[j]) {cout << "IMPROVE\n" << improve << ' ' << j << '\n'; break;}
        }

        greedy.reset();
    }

    return 0;
}