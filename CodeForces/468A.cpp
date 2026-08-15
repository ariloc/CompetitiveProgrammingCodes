#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int main() {
    FAST_IO;

    int n; cin >> n;

    if (n <= 3) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    if (n >= 6) {
        cout << "1 + 5 = 6\n";
        cout << "6 - 6 = 0\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        forsn(i,7,n+1) cout << "0 * " << i << " = 0\n";
        cout << "24 + 0 = 24\n";
        return 0;
    }

    if (n == 4) {
        cout << "1 * 2 = 2\n";
        cout << "2 * 3 = 6\n";
        cout << "6 * 4 = 24\n";
        return 0;
    }

    // n == 5
    cout << "1 + 4 = 5\n";
    cout << "5 * 5 = 25\n",
    cout << "25 + 2 = 27\n";
    cout << "27 - 3 = 24\n";
 
    return 0;
}
