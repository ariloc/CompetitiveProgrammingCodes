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
typedef long double ld;

int const MAXN = 2e5+5;

vi G[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        string s; cin >> s;

        if (s[0] == '0' && s[1] == '1') {
            cout << "NO\n";
        }
        else if (s[n-1] == '0' && s[n-2] == '1') {
            cout << "NO\n";
        }
        else {
            bool posib= true;
            forsn(i,1,n-1)
                if (s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') {
                    posib = false; break;
                }
            if (!posib) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
                vi perm(n,0);
                forn(i,n) if (s[i] == '1') perm[i] = i+1;

                vector<ii> groups;
                int cnt = 0, l = 0;
                forn(i,n) {
                    if (s[i] == '0') {
                        if (!cnt) l = i;
                        cnt++;
                    }
                    else if (cnt) {
                        cnt = 0;
                        groups.pb({l,i});
                    }
                }
                if (cnt) groups.pb({l,n});

                for (auto &i : groups) {
                    forsn(j,i.fst,i.snd) {
                        perm[j] = i.snd-j+i.fst;
                    }
                }

                forn(i,n) cout << perm[i] << ' ';
                cout << '\n';
            }
        }

    }

    return 0;
}
