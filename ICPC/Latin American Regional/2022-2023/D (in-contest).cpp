#include<iostream>
#include<vector>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int n,h,w; cin >> n >> h >> w;

    forn(i,n) {
        char a,b; cin >> a >> b;
        if (h < 0) cout << "N ";
        else if (a == 'Y' || w <= 0) cout << "Y ", --h ,++w;
        else cout << "N ";

        if (w < 0) cout << "N\n";
        else if (b == 'Y' || h <= 0) cout << "Y\n", --w, ++h;
        else cout << "N\n";
    }

    return 0;
}
