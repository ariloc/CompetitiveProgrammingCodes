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

bool allones (string s) {
    forn(i,s.size())
        if(s[i] == '0')
            return false;
    return true;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        string s; cin >> s;

        ll tok = 0;

        while (!allones(s)) {
            string aux = s+s;
            int maxi = 0, cnt = 0; 
            forn(i,aux.size())
                if (aux[i] == '1') cnt = 0;
                else {
                    cnt++;
                    maxi = max(maxi,cnt);
                }

            int shi = (maxi+1)/2;
            tok += shi;

            string auxi;
            forn(i,n)
                if (s[(i-shi+n)%n] == '1') auxi.pb('1');
                else auxi.pb(s[i]);
            swap(s,auxi);
        }

        cout << tok << '\n';
    }

    return 0;
}
