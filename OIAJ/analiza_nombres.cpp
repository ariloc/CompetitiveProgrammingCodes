#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 105;

map<string,int> cnt;

int main() {
    FAST_IO;

    int N; cin >> N;

    string longM = "", common;
    int ap = 0;
    forn (i,N) {
        string s; cin >> s;
        cnt[s]++;
        if (s.size() > longM.size()) longM = s;
        if (cnt[s] > ap) {ap = cnt[s]; common = s;}
    }

    cout << longM << '\n' << common;

    return 0;
}