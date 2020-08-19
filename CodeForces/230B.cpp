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

    int n;
    cin >> n;

    forn(i,n) {
        ll x;
        cin >> x;

        ll a = sqrt(x); bool posib = true;
        if ((a*a) == x and x != 1) {
            for (int j = 2; j*j <= a; j++)
                if (!(a%j)) {posib = false; break;}
            if (posib) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else cout << "NO" << '\n';
    }

    return 0;
}