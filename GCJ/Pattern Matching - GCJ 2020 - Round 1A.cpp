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

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int N; cin >> N;

        string pref,suff,mid; bool nope = false;
        forn (j,N) {
            string s; cin >> s;

            if (!j) {
                int l = 0, r = 0;
                forn (k,s.size()) {
                    if (s[k] == '*') {l = k; break;}
                    pref+=s[k];
                }
                dforn (k,s.size()) {
                    if (s[k] == '*') {r = k; break;}
                    suff+=s[k];
                }
                forsn (k,l+1,r+1) mid += s[k];
            }
            else {
                if (nope) continue;
                int l = 0, r = 0;
                forn (k,s.size()) {
                    if (s[k] == '*') {l = k; break;}
                    if (k >= pref.size()) pref+=s[k];
                    if (s[k] != pref[k])
                        if (pref[k] != '*') {nope = true; continue;}
                }

                int cnt = 0;
                dforn (k,s.size()) {
                    if (s[k] == '*') {r = k; break;}
                    if (cnt >= suff.size()) suff+=s[k];
                    if (s[k] != suff[cnt]) {
                        if (suff[cnt] != '*') {nope = true; continue;}
                    }
                    cnt++;
                }

                forsn (k,l+1,r+1) mid += s[k];
            }
        }

        cout << "Case #" << i+1 << ": ";
        if (nope) cout << "*\n";
        else {
            reverse(all(suff));
            string r = pref+mid+suff;
            forn (k,r.size()) if (r[k] != '*') cout << r[k];
            cout << '\n';

        }
    }

    return 0;
}
