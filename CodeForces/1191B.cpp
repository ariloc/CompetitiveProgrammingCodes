#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9+1;

int main() {
    FAST_IO;

    vector<pair<int,char>> tile;
    forn (i,3) {
        string s;
        cin >> s;
        tile.pb({s[0]-'0',s[1]});
    }

    sort(all(tile));
    int same = 1, consec = 1;

    forsn (i,1,3)
        if (tile[i-1] == tile[i]) same++;

    if (same == 1) same = 0;

    sort(all(tile),[](const pair<int,char> &a, const pair<int,char> &b){return a.snd < b.snd;});
    forsn (i,1,3) {
        if (tile[i-1].snd == tile[i].snd and tile[i].fst == tile[i-1].fst+1) consec++;
    }
    if (consec == 1) consec = 0;
    bool otroConsec = 0;
    forsn (i,1,3)
        if (tile[i-1].snd == tile[i].snd and abs(tile[i-1].fst-tile[i].fst) <= 2) otroConsec = true;

    cout << min({3-same,3-consec,2,(otroConsec ? 1 : INF)});

    return 0;
}