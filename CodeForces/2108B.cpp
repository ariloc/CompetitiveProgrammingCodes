#include <algorithm>
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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,x; cin >> n >> x;

        if (n == 1) {
            if (x >= 1) cout << x << '\n';
            else cout << "-1\n";
            continue;
        }

        if (x == 0) {
            if (n&1) {
                cout << 6 + (n-3) << '\n';
            }
            else {
                cout << n << '\n';
            }
            continue;
        }

        if (x == 1) {
            if (n&1) {
                cout << n << '\n';
            }
            else {
                cout << n-1 + 4 << '\n';
            }
            continue;
        }

        int bits = __builtin_popcount(x) - (x&1);

        int newn = n-bits;

        if (newn <= 0) {
            cout << x << '\n';
            continue;
        }

        if (newn&1) {
            if (x&1) {
                cout << (x^1) + newn << '\n';
            }
            else {
                cout << x + newn + 1 << '\n';
            }
        }
        else {
            if (x&1) {
                cout << x + newn << '\n'; // x^1 + newn + 1
            }
            else {
                cout << x + newn << '\n';
            }
        }
    }

    return 0;
}
