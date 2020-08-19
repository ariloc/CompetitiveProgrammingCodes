#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < ll(n); i++)
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

vector<string> s,t;

int main() {
    FAST_IO;

    int n,m;
    cin >> n >> m;

    forn (i,n) {
        string a;
        cin >> a;
        s.push_back(a);
    }

    forn (i,m) {
        string a;
        cin >> a;
        t.push_back(a);
    }

    int q;
    cin >> q;

    forn (i,q) {
        int x;
        cin >> x;

        string aux;
        aux += s[(!(x%n) ? n-1 : x%n-1)];
        aux += t[(!(x%m) ? m-1 : x%m-1)];

        cout << aux << '\n';
    }

    return 0;
}