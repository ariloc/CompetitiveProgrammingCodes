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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        
        set<string> pref[2];
        pref[0].clear(), pref[1].clear();

        bool posib = false;
        forn(_,n) {
            string s; cin >> s;

            if (posib) continue;

            bool palindrome = true;
            forn(i,(int)s.size()) 
                if (s[i] != s[(int)s.size()-1-i])
                    palindrome = false;

            if (palindrome) {posib = true; continue;}

            if ((int)s.size() == 3) {
                reverse(all(s));
                if (pref[1].count(s)) {posib = true; continue;}
                reverse(all(s));

                string aux; aux += s[1], aux += s[2];
                reverse(all(aux));
                if (pref[0].count(aux)) {posib = true; continue;}

                pref[1].insert(s);
                s.pop_back();
                pref[1].insert(s);
            }
            else {
                reverse(all(s));
                if (pref[0].count(s) || pref[1].count(s)) {posib = true; continue;}
                reverse(all(s));
                pref[0].insert(s);
            }
        }

        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}