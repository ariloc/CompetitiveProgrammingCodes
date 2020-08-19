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
        int n,bst = 1; string s,best;
        cin >> n;
        cin >> s;
        best = s;

        forsn (j,1,n+1) {
            int ind = 0;
            string aux;
            if (j%2 != s.size()%2) {
                ind = j-1;
                while (aux.size() < s.size()) {
                    aux += s[ind];
                    ind++;
                    if (ind >= s.size()) ind = 0;
                }
            }
            else {
                bool backward = false;
                ind = j-1;
                while (aux.size() < s.size()) {
                    aux += s[ind];
                    if (backward) ind--; else ind++;
                    if (ind >= s.size()) {ind = j-2; backward = true;}
                }
            }
            if (aux < best) {bst = j; best = aux;}
        }
        cout << best << '\n' << bst << '\n';
    }

    return 0;
}