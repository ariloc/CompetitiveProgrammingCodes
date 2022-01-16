#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

vector<int> signs;

int main() {
    FAST_IO;
    
    ll cnt[2] = {0,0};
    bool sign = 0;
    string s;
    while (cin >> s) {
        if (s == "=") break;
        if (s == "?") cnt[sign]++, signs.pb(sign);
        if (s == "+") sign = 0;
        if (s == "-") sign = 1;
    }
    int x; cin >> x;

    if ((cnt[0]*x - cnt[1]) >= x && (cnt[0] - cnt[1]*x) <= x) {
        cout << "Possible\n";
        int v = x + cnt[1] - cnt[0];

        int add_aux = (v > 0 ? v : 0);
        int dif_aux = (v < 0 ? abs(v) : 0);

        reverse(all(signs));
        signs.pop_back();
        cout << (add_aux ? min(x,1+add_aux) : 1) << ' ';
        add_aux = max(0,add_aux-x+1);

        while (!signs.empty()) {
            int i = signs.back(); signs.pop_back();
            cout << (i ? "- " : "+ ");
            if (i)
                cout << (dif_aux ? min(x,1+dif_aux) : 1) << ' ', dif_aux = max(0,dif_aux-x+1);
            else
                cout << (add_aux ? min(x,1+add_aux) : 1) << ' ', add_aux = max(0,add_aux-x+1);
        }

        cout << "= " << x;
    }
    else cout << "Impossible\n";

    return 0;
}