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
 
int const MAXN = 1e6+5;
int const P = 31;
int const MOD = 1e9+7;
 
int roll[MAXN], potp[MAXN];
 
int gethash (int l, int r) {
    return ((roll[r+1] - (roll[l] * (ll)potp[r-l+1]))%MOD + MOD)%MOD;
}
 
int main() {
    FAST_IO;
 
    potp[0] = 1;
    forsn(i,1,MAXN) potp[i] = (potp[i-1] * (ll)P)%MOD;
 
    string s; cin >> s;
    int n = (int)s.size();
 
    forn(i,n) roll[i+1] = ((roll[i] * (ll)P) + s[i]-'a')%MOD;
 
    forsn(i,1,n) {
        bool posib = true;
        for (int j = i; j < n; j += i) {
            int b = min(i-1,n-j-1);
            if (gethash(j,j+b) != gethash(0,b)) {
                posib = false; break;
            }
        }
        if (posib) cout << i << ' ';
    }
    cout << n << ' ';
 
    return 0;
}
