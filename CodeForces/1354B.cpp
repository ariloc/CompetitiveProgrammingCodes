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

const int INF = 1e9+2;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (o,t) {
        string s; cin >> s;

        int r = INF;
        int j = 0, cnt[3] = {0,0,0};
        forn (i,s.size()) {
            while (j < s.size() and (!cnt[0] or !cnt[1] or !cnt[2]))
               cnt[s[j++]-'0'-1]++;

            if (j-i < r and cnt[0] and cnt[1] and cnt[2])
                {r = j-i;}

            cnt[s[i]-'0'-1]--;
        }

        if (r == INF) cout << "0";
        else cout << r;
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!