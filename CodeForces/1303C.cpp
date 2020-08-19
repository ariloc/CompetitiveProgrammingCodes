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

const int MAXL = 26;

bitset<26> no;

void dfs(int st, map<int,set<int>> &G, int &prev) {
   cout << (char)(st+'a');
   no[st] = true;
    
   for (auto &i : G[st]) {
      if (i == prev) continue;
      dfs(i,G,st);
   }
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        string s;
        map<int,set<int>> G;
        cin >> s;
        
        forsn (j,1,s.size()) {
            G[s[j-1]-'a'].insert(s[j]-'a');
            G[s[j]-'a'].insert(s[j-1]-'a');
            if (j+1 < s.size()) {
             G[s[j+1]-'a'].insert(s[j]-'a');
             G[s[j]-'a'].insert(s[j+1]-'a');
            }
        }
        bool posib = 1;
        int st = -1, stcnt = 0;
        forn (j,26) {
            if (G[j].size()>2)
              {posib=0;break;}
            if (G[j].size() == 1)
              {st = j; stcnt++;}
        }
        if (stcnt == 1 and s.size() != 1)
           posib=0;
        if (stcnt != 2 and s.size() > 1)
           posib=0;
        if (!posib) {
            cout<<"NO"<<'\n'; continue;
        }
        cout<<"YES"<<'\n';
        if (s.size() > 1) dfs(st,G,st);
        
        forn (j,26)
           if(!no[j]) cout << (char)(j+'a');
        cout << '\n';
        
        no.reset();
    }
    return 0;
}