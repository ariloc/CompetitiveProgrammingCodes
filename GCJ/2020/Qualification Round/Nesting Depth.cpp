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
        string s; cin >> s;

        cout << "Case #" << i+1 << ": ";
        char prev = '\0';
        int cnt = 0;
        forn (j,s.size()) {
            if (s[j] > prev) {
                forn (k,(s[j]-'0')-cnt) cout << '(';
                cnt = s[j]-'0';
            }
            else if (s[j] < prev) {
                forn (k,cnt-(s[j]-'0')) cout << ')';
                cnt = s[j]-'0';
            }
            cout << s[j]; prev = s[j];
        }
        forn (k,cnt) cout << ')';
        cout << '\n';
    }

    return 0;
}
