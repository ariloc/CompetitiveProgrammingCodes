#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

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

int const INF = 1e9;

int main() {
    FAST_IO;

    int n,k,e; cin >> n >> k >> e;

    int l = e, r = n - (k+e);

    if (l >= 10 && r >= 10) cout << "0\n";
    else if (l < 10 && r < 10) {
        int mini = INF; 
        vi pieces;
        forn(i,max(l,r)) if (i+1 != k) pieces.pb(i+1);
        do {
            int rl = l, rr = r;
            vi remain;
            for (auto &i : pieces) {
                if (i <= rl) rl -= i;
                else remain.pb(i);
            }
            for (auto &i : remain) {
                if (i <= rr) rr -= i;
            }
            mini = min(mini,rl+rr);
        } while(next_permutation(all(pieces)));

        cout << mini << '\n';
    } else {
        int mini = INF;
        vi pieces;
        forn(i,min(l,r)) if (i+1 != k) pieces.pb(i+1);
        do {
            int rem = min(r,l);
            for (auto &i : pieces) {
                if (i <= rem) rem -= i;
            }
            mini = min(mini,rem);
        } while(next_permutation(all(pieces)));
        cout << mini << '\n';
    }

    return 0;
}
