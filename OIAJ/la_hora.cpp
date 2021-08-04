#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    //FAST_IO;

    bool pastDoce = false;
    int h,m;
    scanf("%d:%d",&h,&m);

    if (h >= 12) {pastDoce = true;}
    if (h > 12) h-=12;
    if (!h) h = 12;

    if (h-10 < 0) printf("0");
    printf("%d:",h);
    if (m-10 < 0) printf("0");
    printf("%d %s",m,(pastDoce ? "PM" : "AM"));

    return 0;
}