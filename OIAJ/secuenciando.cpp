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

const int MAXL = 58;

int medir(string cad);
int NLONG;
int cantL[MAXL];

void agregar(string &s, int &x, char &c) {
    while (s.size() < x) s+=c;
}
void disminuir(string &s, int &x) {
    while (s.size() > x) s.pop_back();
}

int medirLet (char &c) {
    int low = -1;
    int high = NLONG+1;

    string test;
    while (high-low>1) {
        int mid = (high+low)/2;

        if (mid > test.size()) agregar(test,mid,c);
        else disminuir(test,mid);

        bool res = medir(test);
        if (res) low = mid;
        else high = mid;
    }
    return low;
}

string fuse (string &a, string &b) {
    int j = 0;
    string build;
    forn (i,b.size()) {
        while (j < a.size()) {
            build+=a[j++];
            if (!medir((build+b.substr(i,string::npos))))
                {build.pop_back(); j--; break;}
        }
        build+=b[i];

        if (j >= a.size()) {
            forsn (k,i+1,b.size()) build+=b[k];
            break;
        }
    }
    while (j < a.size()) build+=a[j++];

    return build;
}

string combine(int l, int r, string &s) {
    if (r == l) {
        string tmp;
        forn(i,cantL[s[l]-'A']) tmp += s[l];
        return tmp;
    }

    int m = (l+r)/2;
    string a = combine(l,m,s);
    string b = combine(m+1,r,s);

    if (a.empty()) return b;
    if (b.empty()) return a;
    return fuse(a,b);
}

string secuenciar(int N, string s)
{
    NLONG = N;

    if (s == "AC") {
        char c = 'A';
        int A = medirLet(c);

        string tmp;
        forn(i,A) tmp+='A';
        forn(i,N-A) tmp+='C';

        return tmp;
    }

    int sum = 0;
    forn(i,s.size()-1) {cantL[s[i]-'A'] = medirLet(s[i]); sum += cantL[s[i]-'A'];}
    cantL[s[s.size()-1]-'A'] = N-sum;

    return combine(0,s.size()-1,s);
}
