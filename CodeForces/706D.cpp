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

const int SHIFT = 34;

struct trie {
    map<char,trie> edges;
    int cnt = 0;
    int numericMe = -1;

    void insert(const string &s, const int &me, int i = 0) {
        cnt++;
        if (i == (int)s.size()) {numericMe = me;}
        else edges[s[i]].insert(s,me,i+1);
    }

    bool erase(const string &s, int i = 0) {
        if (i == (int)s.size()) {
            cnt--;
            if (cnt <= 0) return true;
            return false;
        }
        else {
            bool signal = edges[s[i]].erase(s,i+1);
            if (signal) edges.erase(s[i]);
            cnt--;
            if (cnt <= 0) return true;
            return false;
        }
    }

    int find (const string &s, const int &me, int i = 0) {
        if (i == s.size()) return numericMe^me;

        if (s[i] == '0')
            if (edges.count('1')) return edges['1'].find(s,me,i+1);
            else return edges['0'].find(s,me,i+1);
        else
            if (edges.count('0')) return edges['0'].find(s,me,i+1);
            else return edges['1'].find(s,me,i+1);
    }

};

trie T;

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n) {
        char c; int x; cin >> c >> x;
        if (c == '+') {
            bitset<SHIFT> me(x);
            T.insert(me.to_string(),x);
        }
        else if (c == '-') {
            bitset<SHIFT> me(x);
            string tmp = me.to_string();
            bool r = T.erase(tmp);
            if (r) T.edges.erase(tmp[0]);
        }
        else {
            bitset<SHIFT> me(x);
            cout << max(T.find(me.to_string(),x),x) << '\n';
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!