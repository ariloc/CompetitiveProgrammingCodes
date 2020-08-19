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

    int N; string s;
    cin >> N; cin >> s;

    int op = 0,cl = 0;
    int idx = -1, r = 0;
    forn (i,s.size()) {
        if (s[i] == '(') op++;
        else cl++;

        if (op-cl < 0 and idx == -1) idx = i;
        if (!(op-cl) and idx != -1)
            {r += i-idx+1; idx = -1;}
    }

    if ((op-cl) != 0) cout << -1;
    else cout << r;

    return 0;
}