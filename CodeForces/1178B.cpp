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

const int MAXN = 1e6;

ll r[MAXN],l[MAXN];

int main() {
    FAST_IO;

    ll rta = 0;
    string s; cin >> s;

    ll cnt = 0;
    forsn (i,1,s.size()) {
        if (s[i] == 'v' and s[i-1] == 'v')
            cnt++;
        l[i] = cnt;
    }
    cnt = 0;
    dforn (i,s.size()-1) {
        if (s[i] == 'v' and s[i+1] == 'v')
            cnt++;
        r[i] = cnt;
    }

    forn (i,s.size())
        if (s[i] == 'o')
            rta += l[i]*r[i];

    cout << rta;

    return 0;
}