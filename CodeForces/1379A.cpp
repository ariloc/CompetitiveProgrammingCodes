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

const string S = "abacaba";

int aparic(string &s) {
    int cnt = 0;
    size_t lastpos = s.find(S);
    while (lastpos != string::npos and cnt < 2) {
        cnt++;
        lastpos = s.find(S,lastpos+1);
    }

    return cnt;
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n; cin >> n;
        string s; cin >> s;

        int cnt = aparic(s);

        if (cnt > 1) {cout << "No\n"; continue;} // más de una vez
        if (cnt == 1) { // una vez
            cout << "Yes\n";
            for (auto &o : s) cout << (o == '?' ? 'z' : o);
            cout << '\n';
            continue;
        }

        // 0 veces
        int ind = -1;
        forn (j,n-S.size()+1) {
            string tmp = s;
            forn(k,S.size()) if (tmp[j+k] == '?') tmp[j+k] = S[k];
            int val = aparic(tmp);
            if (val == 1) {s = tmp; ind = j; break;}
        }

        if (ind == -1) {cout << "No\n"; continue;} // imposible

        cout << "Yes\n";
        for (auto &o : s) cout << (o == '?' ? 'z' : o);
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!