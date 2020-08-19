#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXL = 28;

bitset<MAXL> done;

int main() {
    FAST_IO;

    int k; cin >> k;
    string s; cin >> s;

    vector<string> proper;
    string accum;
    forn (i,s.size()) {
        if (!done[s[i]-'a'] and (int)proper.size() < k-1) {
            done[s[i]-'a'] = true;
            if (not accum.empty()) {
                proper.pb(accum);
                accum.clear();
            }
        }
        accum += s[i];
    }
    if (!accum.empty()) proper.pb(accum);
    if ((int)proper.size() == k) {
        cout << "YES\n";
        for (auto &i : proper) cout << i << '\n';
    }
    else cout << "NO";

    return 0;
}