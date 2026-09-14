#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define all(c) ((c).begin(),(c).end())
#define pb push_back
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXA = 26;
const char let[] = {'A','C','G','T'};

int cant[MAXA], tmp[MAXA];

vector<int> cromosoma(string cadena) {
    forn(i,cadena.size()) cant[cadena[i]-'A']++;
    forn(i,4) if ((cant[let[i]-'A']&1)) return (vi){-1,-1};
    int j = 0;
    forn(i,cadena.size()) {
        while(j < (int)cadena.size() && (tmp['A'-'A'] <= (cant['A'-'A']/2)) && (tmp['C'-'A'] <= (cant['C'-'A']/2)) && (tmp['G'-'A'] <= (cant['G'-'A']/2)) && (tmp['T'-'A'] <= (cant['T'-'A']/2))) {
            tmp[cadena[j]-'A']++; j++;
        }
        tmp[cadena[j-1]-'A']--;
        if (tmp['A'-'A'] == (cant['A'-'A']/2) && tmp['C'-'A'] == (cant['C'-'A']/2) && tmp['G'-'A'] == (cant['G'-'A']/2) && (tmp['T'-'A'] == (cant['T'-'A']/2)))
            return (vi){i,j-1};
        tmp[cadena[j-1]-'A']++;
        tmp[cadena[i]-'A']--;
    }
    return (vi){-1,-1};
}
