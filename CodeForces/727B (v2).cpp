#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define sz(c) (int)(c).size()
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;
typedef long long ll;

ld const EPS = 1e-8;

int main(){
    FAST_IO;

    string s; cin >> s;

    string auxi;
    vector<string> prod;
    forn(i,sz(s)) {
        if (i && isalpha(s[i]) && isdigit(s[i-1])) {
            prod.pb(auxi);
            auxi = "";
        }
        auxi.pb(s[i]);
    }
    if (!auxi.empty()) prod.pb(auxi);

    ll acc = 0;
    for (auto &ss : prod) {
        int idx = -1;
        forn(i,sz(ss)) {
            if (i && isdigit(ss[i])) {
                idx = i; break;
            }
        }

        auxi = "";
        forsn(i,idx,sz(ss)) auxi.pb(ss[i]);
        int limr = sz(auxi);
        if (sz(auxi) >= 3 && auxi[sz(auxi)-3] == '.') {
            acc += (auxi.back()-'0') + (auxi[sz(auxi)-2]-'0') * 10;
            limr -= 3;
        }

        ll auxnum = 0;
        forn(i,limr) {
            if (auxi[i] == '.') continue;
            auxnum *= 10;
            auxnum += (auxi[i]-'0');
        }

        acc += auxnum * 100LL;
    }

    string r;
    if (acc%100) {
        r.pb((acc%10)+'0');
        r.pb(((acc/10)%10) + '0');
        r.pb('.');
    }
    acc /= 100;

    if (!acc) r.pb('0');

    int cnt = 0;
    while (acc > 0) {
        if (cnt == 3) {
            r.pb('.');
            cnt = 0;
        }
        r.pb((acc%10)+'0');
        acc /= 10;
        ++cnt;
    }

    reverse(all(r));
    
    cout << r << '\n';

    return 0;
}
