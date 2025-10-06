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
    forn(_,t) {
        int n,k; cin >> n >> k;
        if (k == (n*n)-1) cout << "NO\n";
        else if (k < (n*n)-1) {
            cout << "YES\n";
            
            int ac = n*n-k-2;
            cout << "RL";
            int i = 0, j = 2;
            if (n == 2) i = 1, j = 0, cout << '\n';
            while (i < n && j < n && ac > 0) {
                if (!i) cout << "L";
                else cout << "U";
                if (j == n-1) {
                    cout << '\n';
                    j = 0, i++;
                }
                else j++;
                --ac;
            }
            while (i < n && j < n) {
                cout << "D";
                if (j == n-1) {
                    cout << '\n';
                    j = 0, i++;
                } else j++;
            }
        }
        else {
            cout << "YES\n";
            forn(i,n) {
                forn(j,n) cout << "R";
                cout << '\n';
            }
        }
    }

    return 0;
}
