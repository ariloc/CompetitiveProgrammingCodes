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

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        string s;
        int r = 0;
        cin >> s;
        
        bool uno = false;
        int cnt = 0;
        forn (j,s.size()) {
            if (s[j] == '1') {
                uno = true;
                r += cnt;
                cnt = 0;
            }
            else if (uno) cnt++;
        }
        cout << r << '\n';
    }
    return 0;
}