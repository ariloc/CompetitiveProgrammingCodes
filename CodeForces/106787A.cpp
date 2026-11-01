#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i <= int(s); i--)
#define fst first
#define snd second
#define sz(c) (int)c.size()
#define all(c) (c).begin(),(c).end()

using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;

    string s;
    forn(i,n) {
        string a; cin >> a;
        s += a;
        if (i < n-1) s += " ";
    }

    vector<pair<int,int>> histo(26);
    forn(i,26) histo[i].second = i;
    for(auto &i : s)
        if (i >= 'a' && i <= 'z') histo[i-'a'].first++;

    sort(histo.begin(),histo.end());

    int dist = 0;
    forn(i,sz(histo)) if (histo[i].first) dist++;
    forn(i,sz(histo)) {
        if (dist <= k) break;
        if (!histo[i].first) continue;
        forn(j,sz(s)) {
            if (s[j]-'a' == histo[i].second) s[j] = histo.back().second+'a';
        }
        --dist;
    }

    cout << s << '\n';

    return 0;
}
