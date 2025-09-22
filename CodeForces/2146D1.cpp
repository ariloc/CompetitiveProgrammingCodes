#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;

int arr[MAXN];

struct trie{
    map<char, trie> edges;
    int cnta = 0, cntb = 0;

    void insert(const string &s, int i=0){
        cntb++;
        if((int)s.size() != i) edges[s[i]].insert(s, i+1);
    }

    void ainsert(const string &s, const int &a, int b = 0, int i=0){ 
        cnta++;
        if ((int)s.size() == i) {
            arr[b] = a;
        }
        else {
            int bit = s[i]-'0';
            char chr = '0'+(char)(1-bit);
            if (edges.count(chr) && edges[chr].cnta < edges[chr].cntb)
                edges[chr].ainsert(s,a,b|((1-bit)<<(19-i)),i+1);
            else edges[s[i]].ainsert(s,a,b|(bit<<(19-i)),i+1);
        }
    }
};

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int l,r; cin >> l >> r;

        trie T;
        forsn(i,l,r+1) {
            string auxi;
            dforn(k,20) {
                if (i & (1<<k)) auxi.pb('1');
                else auxi.pb('0');
            }
            T.insert(auxi);
        }

        dforsn(i,l,r+1) {
            string auxi;
            dforn(k,20) {
                if (i & (1<<k)) auxi.pb('1');
                else auxi.pb('0');
            }
            T.ainsert(auxi,i);
        }

        ll s = 0;
        forn(i,r-l+1) s += (arr[i] | i);

        cout << s << '\n';
        forn(i,r-l+1) cout << arr[i] << ' ';
        cout << '\n';
    }

    return 0;
}
