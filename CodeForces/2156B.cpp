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
        int n,q; cin >> n >> q;
        string s; cin >> s;

        bool isB = false;
        forn(i,s.size()) if (s[i] == 'B') isB = true;

        if (!isB) {
            forn(_,q) {
                int x; cin >> x;
                cout << x << '\n';
            }
        }
        else {
            forn(_,q) {
                int x; cin >> x;
                int cnt = 0, idx = 0;
                while (x > 0) {
                    if (s[idx] == 'A') x--;
                    else x /= 2;
                    idx = (idx+1)%n;
                    cnt++;
                }
                cout << cnt << '\n';
            }
        }
    }

    return 0;
}
