#include <iostream>
#include <vector>
#include <set>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<string> words;

int main() {
    FAST_IO;
    
    int n; cin >> n;
    forn(i,n) {
        string s; cin >> s;
        words.pb(s);
    }

    string cor = words[0];
    set<char> let;
    forn(k,cor.size()) let.insert(cor[k]);

    int g; cin >> g;
    forn(i,g) {
        string s; cin >> s;

        int cnt = 0;
        for (auto &j : words) {
            bool posib = true;
            forn(k,j.size()) if (cor[k] != j[k] && s[k] == '*') posib = false;
            if (!posib) continue;

            forn(k,j.size()) if (s[k] == '!' && (!let.count(j[k]) || cor[k] == j[k])) posib = false;
            if (!posib) continue;

            forn(k,j.size()) if (s[k] == 'X' && let.count(j[k])) posib = false;
            if (!posib) continue;

            ++cnt;
        }

        cout << cnt << '\n';
    }

    return 0;
}
