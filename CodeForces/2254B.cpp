#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int main() {
    FAST_IO;

    int t;cin  >> t;
    forn(_,t) {
        int n; cin >> n;
        string s; cin >> s;

        vector<pair<int,char>> blocks;
        int cnt = 0;
        forn(i,sz(s)) {
            if (i && s[i] != s[i-1]) {
                blocks.pb({cnt,s[i-1]});
                cnt = 0;
            }
            cnt++;
        }
        blocks.pb({cnt,s.back()});

        int r = sz(blocks);
        forsn(i,1,blocks.size()-1) {
            if (blocks[i].fst == 1 && blocks[i-1].snd == blocks[i+1].snd)
                r = min(r,sz(blocks)-2);
            if (blocks[i].fst == 1)
                r = min(r,sz(blocks)-1);
        }


        cout << r << '\n';
    }

    return 0;
}
