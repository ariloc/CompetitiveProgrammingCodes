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
        int x = 0, y = 0;
        vector<pair<ii,ii>> passed;
        string s; cin >> s;
        forn (j,s.size()) {
            ii antP = {x,y};
            if (s[j] == 'N') y++;
            if (s[j] == 'S') y--;
            if (s[j] == 'W') x--;
            if (s[j] == 'E') x++;
            ii actP = {x,y};
            if (antP.fst > x) swap(antP,actP);
            else if (antP.fst == x and antP.snd > y) swap(antP,actP);
            passed.pb({antP,actP});
        }
        sort(all(passed));

        int r = 5;
        forsn (j,1,passed.size()) {
            if (passed[j] == passed[j-1]) r++;
            else r+=5;
        }

        cout << r << '\n';
    }

    return 0;
}