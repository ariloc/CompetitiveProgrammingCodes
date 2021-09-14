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

vi KMPcompute (string s) { // saco los bordes, prefijos que son sufijos
    int N = (int)s.size();
    vi KMP(N,0);
    forsn(i,1,N) {
        int j = KMP[i-1];
        while (j and s[i] != s[j])
            j = KMP[j-1];
        if (s[i] == s[j]) j++;
        KMP[i] = j;
    }
    return KMP;
}

int main() {
    FAST_IO;

    string s; cin >> s;
 
    int ind = (int)s.size();
    vi show, border = KMPcompute(s);
    while (ind and border[ind-1]) {
        ind = border[ind-1];
        show.pb(ind);
    }
 
    dforn(i,show.size()) cout << show[i] << ' ';
}