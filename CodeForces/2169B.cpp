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

int const MAXN = 3e5+5;

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        string s; cin >> s;

        int n = (int)s.size();
        bool infi = false;
        forsn(i,1,n) {
            if (s[i-1] == '*' && s[i] == '*') infi = true;
            if (s[i] == '*' && s[i-1] == '>') infi = true;
            if (s[i-1] == '>' && s[i] == '<') infi = true;
        }
        forn(i,n-1) {
            if (s[i] == '*' && s[i+1] == '<') infi = true;
        }

        int cnt = 1, maxi = 1;
        forsn(i,1,n) {
            if (s[i] != s[i-1]) {
                maxi = max(maxi,cnt); cnt = 0;
            }
            cnt++;
        }
        maxi = max(maxi,cnt);

        forn(i,n) {
            if (s[i] == '*') maxi = max(maxi, max(i+1, n-i));
        }

        if (infi) cout << "-1\n";
        else cout << maxi << '\n';
    }
   
    return 0;

}
