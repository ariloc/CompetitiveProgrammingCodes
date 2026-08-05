#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXNN = 2e5+5;
int const MAXN = 1<<(32-__builtin_clz(MAXNN));
double const PI = acos(-1);

struct base{
    double r,i;
    base(double r=0, double i=0):r(r), i(i){}
    double real()const{return r;}
    void operator/=(const int c){r/=c, i/=c;}
};
base operator*(const base &a, const base &b){
    return base(a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r);}
base operator+(const base &a, const base &b){
    return base(a.r+b.r, a.i+b.i);}
base operator-(const base &a, const base &b){
    return base(a.r-b.r, a.i-b.i);}
vector<int> rev; vector<base> wlen_pw;
inline static void fft(base a[], int n, bool invert) {
    forn(i, n) if(i<rev[i]) swap(a[i], a[rev[i]]);
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert?-1:+1);
		int len2 = len>>1;
		base wlen (cos(ang), sin(ang));
		wlen_pw[0] = base (1, 0);
        forsn(i, 1, len2) wlen_pw[i] = wlen_pw[i-1] * wlen;
		for (int i=0; i<n; i+=len) {
			base t, *pu = a+i, *pv = a+i+len2,  *pu_end = a+i+len2, *pw = &wlen_pw[0];
			for (; pu!=pu_end; ++pu, ++pv, ++pw)
				t = *pv * *pw, *pv = *pu - t,*pu = *pu + t;
		}
	}
	if (invert) forn(i, n) a[i]/= n;}
inline static void calc_rev(int n){//precalculo: llamar antes de fft!!
    wlen_pw.resize(n), rev.resize(n);
    int lg=31-__builtin_clz(n);
    forn(i, n){
		rev[i] = 0;
        forn(k, lg) if(i&(1<<k)) rev[i]|=1<<(lg-1-k);
    }}
inline static void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    int n=1; while(n < max(sz(a), sz(b))) n <<= 1; n <<= 1;
    calc_rev(n);
	fa.resize (n),  fb.resize (n);
	fft (&fa[0], n, false),  fft (&fb[0], n, false);
	forn(i, n) fa[i] = fa[i] * fb[i];
	fft (&fa[0], n, true);
	res.resize(n);
    forn(i, n) res[i] = int (fa[i].real() + 0.5); }
void toPoly(const string &s, vector<int> &P){//convierte un numero a polinomio
    P.clear();
    dforn(i, sz(s)) P.pb(s[i]-'0');}

vi a,b;

int rta[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {int x; cin >> x; a.pb(x);}
    forn(i,n) {int x; cin >> x; b.pb(x);}

    vi p1,p2;
    forn(k,2) {
        p1.resize(0);p2.resize(0);

        forn(i,n) if (a[i]) p1.pb(a[i]); else p1.pb(0);
        forn(i,n) if (b[i]) p2.pb(0); else p2.pb(1);
        if (k) swap(p1,p2);

        reverse(all(p1)); p1.resize(2*n,0);
        forn(i,n) p2.pb(p2[i]);

        vi mul;
        multiply(p1,p2,mul);
        forn(i,n) rta[i] += mul[n-1+i];

        swap(a,b);
    }

    int maxi = 0;
    forn(i,n) maxi = max(maxi,rta[i]);

    cout << maxi << '\n';

    return 0;
}
