#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

string tab[2];

int main() {
    FAST_IO;

    cin >> tab[0];
    cin >> tab[1];

    int cnt = 0;
    forsn(i,1,sz(tab[0])) {
        if (tab[0][i-1] == '0' && tab[1][i-1] == '0') {
            if (tab[0][i] == '0') {
                ++cnt;
                tab[0][i-1] = tab[1][i-1] = tab[0][i] = 'X';
            }
            else if (tab[1][i] == '0') {
                ++cnt;
                tab[0][i-1] = tab[1][i-1] = tab[1][i] = 'X';
            }
        }
        else if (tab[0][i] == '0' && tab[1][i] == '0') {
            if (tab[0][i-1] == '0') {
                ++cnt;
                tab[0][i] = tab[1][i] = tab[0][i-1] = 'X';
            }
            else if (tab[1][i-1] == '0') {
                ++cnt;
                tab[0][i] = tab[1][i] = tab[1][i-1] = 'X';
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}
