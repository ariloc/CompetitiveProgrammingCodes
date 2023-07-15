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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        string s; cin >> s;
        map<char,int> A;
        forn(i,s.size()) A[s[i]] = i;

        int n; cin >> n;

        vector<pair<vi,int>> lst;
        vector<string> inp;
        forn(i,n) {
            string w; cin >> w;
            inp.pb(w);

            vi aux;
            for(auto &j : w) aux.pb(A[j]);

            lst.pb({aux,i});
        }

        sort(all(lst));

        for (auto &i : lst) cout << inp[i.snd] << '\n';
        cout << '\n';
    }
        
    return 0;
}
