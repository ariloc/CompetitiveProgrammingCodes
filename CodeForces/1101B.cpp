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

    string s; cin >> s;
    int sz = s.size();

    int l = -1, r = -1;
    forn (i,s.size())
        if (s[i] != '[') sz--;
        else {l = i; break;}

    dforn (i,s.size())
        if (s[i] != ']') sz--;
        else {r = i; break;}

    if (l == -1 or r == -1) {cout << -1; return 0;}

    int lc = -1, rc = -1;
    forsn (i,l+1,r)
        if (s[i] != ':') sz--;
        else {lc = i; break;}

    dforsn (i,l+1,r)
        if (s[i] != ':') sz--;
        else {rc = i; break;}

    if (rc == lc or lc == -1 or rc == -1) {cout << -1; return 0;}

    forsn (i,lc+1,rc)
        if (s[i] != '|') sz--;

    cout << sz;

    return 0;
}