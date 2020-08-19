#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    string s; cin >> s;

    ll rot = 0;
    char let = 'a';
    forn (i,s.size()) {
        int a = abs(let-s[i]);
        int b;
        if (s[i] >= let) b = abs('a'-let)+abs('z'-s[i])+1;
        else b = abs('z'-let)+abs('a'-s[i])+1;
        rot += min(a,b);
        let = s[i];
    }

    cout << rot;

    return 0;
}