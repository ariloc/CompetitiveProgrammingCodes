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

const int MAXN = 28;

int cnt[MAXN];

int main() {
    FAST_IO;

    string s; cin >> s;
    if (s.size() < 26) {cout << -1; return 0;}
    int N = s.size();

    int j = 0;
    forn (i,N) {
        while (j < N and j-i < 26 and (s[j] == '?' or !cnt[s[j]-'A']))
            if (s[j] != '?') cnt[s[j++]-'A']++;
            else j++;

        if (j-i == 26) {
            forn (k,i) if (s[k] == '?') cout << 'A'; else cout << s[k];
            forsn (k,i,j)
                if (s[k] == '?') {
                    forn (o,26)
                        if (!cnt[o]) {cout << (char)(o+'A'); cnt[o]++; break;}
                }
                else cout << s[k];
            forsn(k,j,N) if (s[k] == '?') cout << 'A'; else cout << s[k];
            return 0;
        }
        if (s[i] != '?') cnt[s[i]-'A']--;
    }
    cout << -1;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!