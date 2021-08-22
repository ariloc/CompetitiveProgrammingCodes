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

const int MAXN = 300005;
const int SHIFT = 30;

struct trie {
    map<bool,trie> edges;
    int numericMe = -1;
    int cnt = 0;

    void insert(const string &s, const int &me, int i = 0) {
        cnt++;
        if (i == (int)s.size()) numericMe = me;
        else edges[s[i]-'0'].insert(s,me,i+1);
    }

    int find(const string &s, int i = 0) {
        if (i == (int)s.size()) return numericMe;
        else if (edges.count(s[i]-'0')) return edges[s[i]-'0'].find(s,i+1);
        else if (!(s[i]-'0')) return edges[1].find(s,i+1);
        else return edges[0].find(s,i+1);
    }

    bool erase(const string &s, int i = 0) {
        if (i == (int)s.size()) {
            cnt--;
            if (cnt <= 0) return true;
            return false;
        }
        else {
            bool signal = edges[s[i]-'0'].erase(s,i+1);
            if (signal) edges.erase(s[i]-'0');
            cnt--;
            if (cnt <= 0) return true;
            return false;
        }
    }

};

trie T;
int cipher[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    forn(i,N) cin >> cipher[i];
    forn(i,N) {
        int x; cin >> x;
        bitset<SHIFT> tmp(x);
        T.insert(tmp.to_string(),x);
    }

    forn (i,N) {
        bitset<SHIFT> tmp(cipher[i]);
        int val = T.find(tmp.to_string());
        bitset<SHIFT> tmp2(val);

        string strTmp = tmp2.to_string();
        bool tmpSignal = T.erase(strTmp);
        if (tmpSignal) T.edges.erase(strTmp[0]);

        cout << (val^cipher[i]) << ' ';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!