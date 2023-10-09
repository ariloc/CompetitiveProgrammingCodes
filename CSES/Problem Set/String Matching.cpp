#include<bits/stdc++.h>
 
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
 
int const MAXN = 2e6+5;
 
int Z[MAXN];
 
int main() {
    FAST_IO;
 
    string s; cin >> s;
    string p; cin >> p;
 
    string aux = p + "$" + s;
    int n = (int)aux.size();
 
    int l = 0, r = 0;
    forsn(i,1,n) {
        if (i < r) Z[i] = min(Z[i-l],r-i);
        while (Z[i]+i < n && aux[Z[i]] == aux[Z[i]+i]) ++Z[i];
        if (Z[i]+i > r) l = i, r = Z[i]+i;
    }
 
    int rta = 0;
    forn(i,n) if (Z[i] == (int)p.size()) ++rta;
    cout << rta << '\n';
 
    return 0;
}
