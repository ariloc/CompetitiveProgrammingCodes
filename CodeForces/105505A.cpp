#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define sz(c) (int)(c).size()
#define pb push_back
#define all(c) (c).begin(),(c).end()

using namespace std;

int main() {
    string s; cin >> s;

    set<char> let;
    forn(i,sz(s)) {
        let.insert(s[i]);
        if (sz(let) + i+1 == sz(s)) {
            string cur;
            forn(j,i+1) cur.pb(s[j]);
            sort(all(cur));
            cur.erase(unique(all(cur)),cur.end());
            if (cur == s.substr(i+1,sz(let))) 
                return cout << sz(s)-sz(let) << '\n', 0;
        }
    }

    return 0;
}
