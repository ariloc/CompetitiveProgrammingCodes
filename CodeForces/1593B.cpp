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

const int INF = 2e9;

int calc (string x, char l, char r) {
    int pl = -1, pr = -1;
    dforn(i,x.size()) {
        if (pr != -1 && pl == -1 && x[i] == l) pl = i;
        if (pr == -1 && x[i] == r) pr = i;
    }
    return (int)x.size() - pl - 2;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        string x; cin >> x;
        
        int mini = calc(x,'0','0');
        mini = min(mini,calc(x,'2','5'));
        mini = min(mini,calc(x,'5','0'));
        mini = min(mini,calc(x,'7','5'));

        cout << mini << '\n';
    }

    return 0;
}