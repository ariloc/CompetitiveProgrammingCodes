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

string const PALOS = "OCEB";
int const INF = 10000;

int card[12][4];

int stair (int s, int p) {
    int len = 0;
    forsn(i,s,12) if (card[i][p]) ++len; else break;
    if (len < 3) return -1;
    forsn(i,s,s+len) --card[i][p];
    return p;
}

void restore (int s, int p, int len) {
    forsn(i,s,s+len) ++card[i][p];
}

int legs() {
    int pts = 0;
    forn(k,12) {
        int cnt = 0;
        forn(r,4) cnt += (card[k][r]>0);
        if (cnt < 3) pts += cnt*(k+1);
    }
    return pts;
}

int chinchon(vector<int> &numero, string palo) {
    forn(i,7) {
        int ind = PALOS.find(string(1,palo[i]));
        card[numero[i]-1][ind]++;
    }
    int mini = legs();
    mini = !mini ? -10 : mini;
    forn(i,10) forn(j,4) {
        int len = stair(i,j);
        if (len == -1) continue;
        forn(i2,10) forn(j2,4) {
            int len2 = stair(i2,j2);
            if (len == -1) continue;

            int val = legs();
            mini = min(mini,!val ? -10 : val);

            restore(i2,j2,len2);
        }
        int val = legs();
        mini = min(mini,!val ? -50 : val);
        restore(i,j,len);
   }

    return mini;
}
