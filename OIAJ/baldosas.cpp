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

const char C[] = {'A','R','V'};

int main() {
    FAST_IO;
    freopen("baldosas.in","r",stdin);
    freopen("baldosas.out","w",stdout);

    string s;
    cin >> s;

    int cant = s.size()/3;
    int col[] = {cant,cant,cant}; // A,R,V
    int pos = 0;
    forn (i,s.size())
        if (s[i] != '*') {
            if (s[i] == 'A') col[0]--;
            else if (s[i] == 'R') col[1]--;
            else col[2]--;

            pos = i; break;
        }

    dforn (i,pos) {
        int chosen = 0;
        forn(j,3)
            if (C[j] != s[i+1] and col[j] > col[chosen])
                chosen = j;

        col[chosen]--;
        s[i] = C[chosen];
    }

    forsn(i,pos+1,s.size()) {
        int chosen = 0;
        forn(j,3)
            if (C[j] != s[i-1] and col[j] >= col[chosen])
                chosen = j;

        col[chosen]--;
        s[i] = C[chosen];
    }

    cout << s;

    return 0;
}