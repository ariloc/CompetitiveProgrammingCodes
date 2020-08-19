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
        int x; cin >> x;
        string s; cin >> s;

        bool posib = true;
        forn (j,x/2) {
            int dif = abs(s[j]-s[s.size()-1-j]);
            if (dif == 1 or dif > 2)
                {posib = false; break;}
        }

        if (posib) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}