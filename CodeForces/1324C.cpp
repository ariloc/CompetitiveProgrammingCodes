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

const int MAXN = 5000;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        string s;
        cin >> s;

        int cnt = 0, best = 1;
        forn (j,s.size()) {
            if (s[j] == 'L') cnt++;
            else {best = max(best,cnt+1); cnt = 0;}
        }
        if (cnt) best = max(best,cnt+1);

        cout << best << '\n';
    }

    return 0;
}