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

const int MAXL = 27;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int occur[MAXL];
        memset(occur,0,sizeof(occur));
        int n,k; cin >> n >> k;
        string s; cin >> s;
        forn (j,n)
            occur[s[j]-'a']++;
        string r;

        // getting first one
        int kAux = k;
        int ind = -1, cntY = 0;
        char flag = 'N';
        forn (j,MAXL) {
            if (!occur[j]) continue;
            kAux -= occur[j];
            if (kAux <= 0) {
                if (!cntY) {
                    occur[j] = occur[j]-(kAux+occur[j]);
                    r += (j+'a'); ind = j; break;
                }
                else
                    {flag = j; break;}
            }
            cntY++;
        }
        if (flag != 'N') {cout << (char)(flag+'a') << '\n'; continue;}

        string aux; int cnt = 0;
        forsn (j,ind,MAXL)
            if (occur[j]) {aux += string(occur[j],j+'a'); cnt++;}

        if (cnt == 1)
            r += string((occur[int(aux[0]-'a')]+k-1)/k,aux.back());
        else r+=aux;

        cout << r << '\n';
    }

    return 0;
}