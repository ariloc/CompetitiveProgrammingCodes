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

const int MAXL = 30;
int cnt[MAXL];

int main() {
    FAST_IO;

    int q; cin >> q;

    forn (i,q) {
        string s,t,p; cin >> s >> t >> p;

        memset(cnt,0,sizeof(cnt));
        bool posib = true;
        int ind = 0;
        forn (j,s.size()) {
            while (t[ind++] != s[j] and ind < t.size());
            if (ind >= t.size() and t[ind-1] != s[j]) {posib = false; break;}
        }

        forn (j,s.size()) cnt[s[j]-'a']++;
        forn (j,p.size()) cnt[p[j]-'a']++;
        forn (j,t.size()) cnt[t[j]-'a']--;
        forn (j,MAXL) if (cnt[j] < 0) {posib = false; break;}

        if (posib) cout << "YES\n"; else cout << "NO\n";
    }

    return 0;
}