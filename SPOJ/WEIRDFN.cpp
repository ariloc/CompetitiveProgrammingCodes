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

int const MOD = 1e9+7;

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int a,b,c,n; scanf("%d %d %d %d",&a,&b,&c,&n);

        priority_queue<int> mini; // primeros n/2 techo
        priority_queue<int,vi,greater<int>> maxi;

        ll sum = 1;
        mini.push(1);
        forsn(i,1,n) {
            int med = mini.top();
            int cur = sumMod((a*(ll)med)%MOD, sumMod((b * (ll)(i+1))%MOD, c));
            sum += cur;
            
            if (cur >= med) maxi.push(cur);
            else mini.push(cur);
            while ((int)maxi.size() > (int)mini.size()) mini.push(maxi.top()), maxi.pop();
            while ((int)mini.size() > (int)maxi.size()+1) maxi.push(mini.top()), mini.pop();
        }

        printf("%lld\n",sum);
    }

    return 0;
}
