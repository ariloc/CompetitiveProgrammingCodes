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

const int MAXN = 30;

int opt[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;
    string s; cin >> s;
    bool posib = false;

    forn (i,N) {
        opt[s[i]-'a']++;
        if (opt[s[i]-'a'] > 1) {posib = true; break;}
    }

    int cnt = 0;
    forn (i,MAXN) if (opt[i] > 0) cnt++;

    if (posib or cnt == 1) cout << "Yes"; else cout << "No";

    return 0;
}