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

    string r;
    int n,m,k; cin >> n >> m >> k;

    forn (i,k) {int a,b; cin >> a >> b;}
    forn (i,k) {int a,b; cin >> a >> b;}

    r += string(n-1, 'D');
    r += string(m-1, 'R');

    forn (i,n) {
        if (!(i%2)) r += string(m-1,'L');
        else r += string(m-1, 'R');
        r += 'U';
    }
    if (r.back() == 'U') r.pop_back();

    cout << r.size() << '\n' << r;

    return 0;
}