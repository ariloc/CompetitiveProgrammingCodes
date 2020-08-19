#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int N;
        cin >> N;
        vi idx; int prev = -1;
        forn (j,N) {
            int x;
            cin >> x;
            if ((!(x%2)) and idx.empty()) idx.push_back(j+1);
            else if (prev != -1 and !((x+prev)%2) and idx.empty()) {
                idx.push_back(j+1); idx.push_back(j);
            }
            prev = x;
        }
        if (idx.empty()) cout << "-1\n";
        else {cout << idx.size() << '\n'; for(auto &j : idx) cout << j << ' '; cout << '\n';}
    }

    return 0;
}