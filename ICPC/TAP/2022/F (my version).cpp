
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
typedef long double ld;

vector<string> lst;

int main() {
    FAST_IO;

    int n,c; cin >> n >> c;

    forn(_,n) {
        string x; cin >> x;
        forn(i,x.size()) 
            if (x[i] == '*') {
                forsn(j,'a','z'+1)
                    x[i] = j, lst.pb(x);
                break;
            }
    }

    sort(all(lst)); lst.pb("A"); // dummy
    int cnt = 1, maxi = 1;
    string rta = lst[0];
    forsn(i,1,lst.size()) {
        if (lst[i] != lst[i-1]) cnt = 0;
        cnt++;
        if (cnt > maxi) maxi = cnt, rta = lst[i];
    }

    cout << rta << ' ' << maxi;
    
    return 0;
}
