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

const int MAXL = 18;

struct trie {
    map<char,trie> edges;
    int cnt = 0;

    void insert(const string &s, int &sum, int i = 0) {
        if ((int)s.size() < i) return;
        cnt += sum;
        if ((s[i]-'0') & 1) edges['1'].insert(s,sum,i+1);
        else edges['0'].insert(s,sum,i+1);
    }

    int search(const string &s, int i = 0) {
        if ((int)s.size() == i) return cnt;
        else return edges[s[i]].search(s,i+1);
    }
};

int main() {
    FAST_IO;

    trie T;

    int N; cin >> N;

    forn (i,N) {
        char c; cin >> c;
        string s; cin >> s;

        if (c == '?') {
            reverse(all(s));
            while (s.size() < MAXL) s+='0';
            cout << T.search(s) << '\n';
        }
        else {
            int add = (c == '+' ? 1 : -1);
            string send;
            dforn(j,s.size()) send+=s[j];
            while (send.size() < MAXL) send+='0';
            T.insert(send,add);
        }
    }

    return 0;
}