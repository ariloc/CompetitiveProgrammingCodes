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

const int MAXN = 1000;

int height[MAXN];
char mat[MAXN][MAXN];

int main() {
    FAST_IO;

    forn (i,MAXN) forn(j,MAXN) mat[i][j] = ' ';

    int N; cin >> N;
    string s; cin >> s;

    vi indice; int maxi = 0;
    forn (i,s.size()) {
        if (s[i] == '[') {indice.pb(i); maxi = max(maxi,(int)indice.size()-1);}
        else {
            int ind = indice.back(), sz = indice.size();
            indice.pop_back();
            height[i] = height[ind] = sz-1;
        }
    }

    maxi = maxi*2+3;

    bool left = true;
    int ind = 0;
    forn (i,s.size()) {
        if (s[i] == '[') {
            if (!left) ind++;
            mat[height[i]][ind] = '+'; mat[maxi-height[i]-1][ind] = '+';
            forsn (j,height[i]+1,maxi-height[i]-1) mat[j][ind] = '|';
            ind++; mat[height[i]][ind] = '-'; mat[maxi-height[i]-1][ind] = '-';

            left = true;
        } else {
            if (left) ind+=2;

            mat[height[i]][ind] = '-'; mat[maxi-height[i]-1][ind] = '-';
            ind++; mat[height[i]][ind] = '+'; mat[maxi-height[i]-1][ind] = '+';
            forsn (j,height[i]+1,maxi-height[i]-1) mat[j][ind] = '|';

            left = false;
        }
    }

    forn (i,maxi) {forn(j,ind+1) cout << mat[i][j]; cout << '\n';}

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!