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

int const MAXA = 26;

int cnt[MAXA];

int main() {
    FAST_IO;

    string s; cin >> s;
    forn(i,s.size()) cnt[s[i]-'A']++;
    
    cout << min(cnt['T'-'A'], min(cnt['P'-'A'], cnt['A'-'A']+cnt['U'-'A']));

    return 0;
}
