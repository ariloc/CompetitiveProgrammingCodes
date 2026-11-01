#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i <= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) (int)c.size()
#define all(c) (c).begin(),(c).end()

using namespace std;
typedef long long ll;
typedef vector<int> vi;

string tm1,tm2,ret;

int main() {
    string s; cin >> s;

    int is = -1;
    forn(i,sz(s)) if (s[i]=='+') is = i;

    int tam = is;

    tm1 = s.substr(0,tam);
    tm2 = s.substr(tam+1,tam);
    ret = s.substr(tam+1+tam+1,tam);

    for (auto &i : tm1) i -= 'a';
    for (auto &i : tm2) i -= 'a';
    for (auto &i : ret) i -= 'a';

    vi rta;
    forn(a,10) forn(b,10) forn(c,10) forn(d,10) forn(e,10) {
        vi vals = {a,b,c,d,e};
        vi auxi = vals;

        sort(all(auxi));
        auxi.erase(unique(all(auxi)),auxi.end());
        if (sz(auxi) != 5) continue;

        int carry = 0;
        bool ok = true;
        vi digs;
        dforn(i,tam) {
            int dig = vals[tm1[i]] + vals[tm2[i]] + carry;
            digs.pb(dig);
            carry = dig / 10;
            dig %= 10;

            if (dig != vals[ret[i]]) {
                ok = false; break;
            }
        }

        if (ok && !carry) {
            rta = vals; goto out;
        }
    }

    out:
    if (rta.empty()) {
        cout << "impossible\n";
        return 0;
    }

    for (auto &i : rta) cout << i;
    cout << '\n';

    return 0;
}
