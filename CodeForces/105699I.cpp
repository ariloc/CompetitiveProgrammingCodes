#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = 0; i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        string s; int m,b;
        cin >> s >> m >> b;

        if (s == "WIN")
            return 0;

        if (b >= m/3 && m >= 3)
            cout << "SKIP" << endl;
        else cout << "PLAY" << endl;
    }
    
    return 0;
}
