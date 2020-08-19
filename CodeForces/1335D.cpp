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
        vector<string> sud;
        forn (j,9)
            {string s; cin >> s; sud.pb(s);}

        int a = 0, b = 0;
        forn (j,9) {
            sud[a][b] = (sud[a][b] == 1+'0' ? 2+'0' : 1+'0');
            b++;
            a+=3; if (a >= 9) a %= 8;
        }

        forn (j,9) cout << sud[j] << '\n';
    }

    return 0;
}