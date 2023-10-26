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

int main() {
    FAST_IO;

    int n;
    while (cin >> n) {
        if (n == -1) break;
        vector<vi> plays;
        plays.pb({});
        forn(i,n-1) {
            string s; cin >> s;
            vi auxi;
            for (auto &j : s) auxi.pb(j-'1');
            reverse(all(auxi));
            plays.pb(auxi);
        }
        vi ret;
        while(true) {
            bool posib = false;
            forn(i,n) if (!plays[i].empty()) posib = true;
            if (!posib) break;

            int cand = -1;
            forsn(i,1,n) if (!plays[i].empty() && plays[i].back() > 0 && plays[plays[i].back()].back() == i) {
                cand = i; break;
            }
            if (cand != -1) {
                plays[plays[cand].back()].pop_back();
                plays[cand].pop_back();
            }
            else {
                forsn(i,1,n) if (!plays[i].empty() && plays[i].back() == 0) {
                    ret.pb(i);
                    plays[i].pop_back();
                    break;
                }
            }
        }

        for (auto &i : ret) cout << i+1;
        cout << '\n';
    }

    return 0;
}
