#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define forn(i,n) for(int i = 0; i < n; i++)
#define forsn(i,s,n) for(int i = s; i < n; i++)
#define dforn(i,n) for(int i = n-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = n-1; i >= s; i--)

#define MAXN 1000

int valores[MAXN];

void merge (int l, int r, int m, int *arr) {
    int nl = m-l+1, nr = r-m;
    int larr[nl], rarr[nr];

    forn (i,nl) larr[i] = arr[l+i];
    forn (i,nr) rarr[i] = arr[m+i+1];

    int k = l, i = 0, j = 0;
    while (i < nl && j < nr)
        if (larr[i] <= rarr[j]) arr[k++] = larr[i++];
        else arr[k++] = rarr[j++];

    while (i < nl) arr[k++] = larr[i++];
    while (j < nr) arr[k++] = rarr[j++];
}

void divide (int l, int r, int *arr) {
    if (l >= r) return;

    int mid = l + (r-l)/2;
    divide(l,mid,arr);
    divide(mid+1,r,arr);

    merge(l,r,mid,arr);
}

int main() {
    int N; scanf("%d",&N);
    forn (i,N) scanf("%d",&valores[i]);

    divide(0,N-1,valores);

    forn (i,N) printf("%d ",valores[i]);

    return 0;
}
