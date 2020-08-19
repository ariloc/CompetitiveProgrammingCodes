#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int n, cantO = 0, even = -1, odd = -1;
        ll sum = 0;
        cin >> n;
        forn (j,n) {
            int x;
            cin >> x;
            sum += x;
            if (x % 2) {cantO++; odd = j;}
            else even = j;
        }

        if (cantO % 2) cout << "YES";
        else if (even != -1 and odd != -1) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }

    return 0;
}