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
 
const int MAXN = 1e6+10;
 
int divs[MAXN];
bitset<MAXN> done;
 
void getDiv(int N) {
    for (int i = 2; i <= N; i++)
        for (int j = i+i; j <= N; j+=i) divs[j]++;
    divs[1] = -1;
}
 
int main() {
    FAST_IO;
 
    getDiv(MAXN);
    int n; cin >> n;
 
    forn (i,n) {
        int x; cin >> x;
        cout << divs[x]+2 << '\n';
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!