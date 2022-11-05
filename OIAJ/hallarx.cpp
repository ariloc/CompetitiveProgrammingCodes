#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef long double ld;
 
int hallarx(string &A, string &B, string &C) {
    int carry = 0;

    int n = max(A.size(), max(B.size(), C.size()));

    string a,b,c;
    a = A; b = B; c = C;
    reverse(all(a)); reverse(all(b)); reverse(all(c));
    while ((int)a.size() < n) a.pb('0');
    while ((int)b.size() < n) b.pb('0');
    while ((int)c.size() < n) c.pb('0');
    reverse(all(a)); reverse(all(b)); reverse(all(c));

    int ret = -1;
    dforn(i,n) {
        int s = a[i]-'0' + b[i]-'0' + carry;
        if (c[i] == 'x')
            c[i] = ret = s % 10, c[i] += '0';
        if (b[i] == 'x')
            b[i] = ret = ((c[i]-'0' - a[i]+'0' - carry) + 10)%10, b[i] += '0';
        if (a[i] == 'x')
            a[i] = ret = ((c[i]-'0' - b[i]+'0' - carry) + 10)%10, a[i] += '0';
        carry = s / 10;
    }

    carry = 0;
    dforn(i,n) {
        int s = a[i]-'0' + b[i]-'0' + carry;

        if ((s%10) != (c[i]-'0'))
            return -1;

        carry = s / 10;
    }

    if (carry) return -1;

    return ret;
}
