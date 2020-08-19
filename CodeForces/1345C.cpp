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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n; cin >> n;

        vi trucho;
        forn (j,n) {
            ll x; cin >> x;
            trucho.pb((((j+x)%n)+n)%n);
        }

        sort(all(trucho));

        bool posib = true;
        forsn (j,1,trucho.size())
            if (trucho[j-1] == trucho[j]) {posib = false; break;}

        if (posib) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}