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
        int a,b,p; string s;
        cin >> a >> b >> p;
        cin >> s;

        int lastSt = -1;
        dforn(j,s.size()-2) {
            if (s[j] != s[j+1]) {
                if (s[j+1] == 'B') p -= b;
                else p -= a;

                if (p >= 0) lastSt = j+2;
                else break;
            }
        }
        if (s[0] == 'B') p -= b;
        else p -= a;
        if (p >= 0) lastSt = 1;
        if (lastSt == -1) lastSt = s.size();

        cout << lastSt << '\n';
    }

    return 0;
}