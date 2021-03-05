#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const char letras[3] = {'a','b','c'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> pal;

    forn (i,N) {
        string s;
        cin >> s;
        pal.push_back(s);
    }

    forn (i, pal.size()) {
        string s = pal[i];
        forn (j,s.size()) {
            char x = s[j];
            if (x == '?') {
                forn (k,3) {
                    if (j-1 >= 0 and letras[k] == s[j-1]) continue;
                    if (j+1 < s.size() and letras[k] == s[j+1]) continue;
                    s[j] = letras[k];
                    break;
                }
            }
            else {
                if (j-1 >= 0 and s[j-1] == x) goto END;
                if (j+1 < s.size() and s[j+1] == x) goto END;
            }
        }
        cout << s << '\n';
        continue;
        END:
        cout << -1 << '\n';
    }

    return 0;
}
