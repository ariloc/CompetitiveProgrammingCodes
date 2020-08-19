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

    int N;
    string s;
    cin >> N;
    cin >> s;

    int ind = -1, cnt = 0;

    forn (j,N) {
        forn (i,N) {
            if (i+1 < s.size() and s[i+1] == s[i]-1) goto DO;
            if (i-1 >= 0 and s[i-1] == s[i]-1) goto DO;
            continue;
            DO:
                if (ind == -1 or s[ind] <= s[i]) ind = i;
        }
        if (ind == -1) break;
        s.erase(ind,1);
        ind = -1; cnt++;
    }

    cout << cnt;

    return 0;
}