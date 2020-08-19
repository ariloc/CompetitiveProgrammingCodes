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

const int MAXN = 4002;
const int INF = 1e9;

struct rango {
    int l,r,id;
    bool A;

    bool operator< (const rango &o) const {
        return o.r > r;
    }
};

/*
    Hago una DP viendo RANGOS. Es decir, las decisiones en el problema es take o not take. ¿Cómo?
    Bueno... cuando estoy en un "rango" de un pedido, puedo seguir por los de mi mismo rango,
    o ir hacia el otro. Entonces calculo de un punto a otro, cuánta distancia puedo recorrer en
    mis pedidos. Y a su vez, si cambio a la otra "tanda" de los pedidos de la otra persona
    qué tanto puedo juntar. El que más junta, gana.

    Al plantear la DP, sería la tabla:

      0 1 2 3 4 ...
    0 o o o o o ...
    1 o o o o o ...

    0 y 1 a la izquierda sería el tipo de pedido, Alfio o Belén. Por si no quedó claro, no se pueden
    enganchar pedidos de distinta persona, pero si de uno, y lo aprovechamos para alargar con cada
    uno lo más posible y probar casos.

    Mientras 0,1,2,3,4... representan los números de pedidos, cuando todo está ya ordenado.
    Idealmente los ordenamos según cuándo termina cada rango, para verificar eficientemente si de un
    rango puedo ir hacia otro, y recorrer linealmente con un for.

    Así es fácil obtener el número final...luego reconstruir ya es una mayor tarea.
    Como directamente decidimos enganchar los extremos de las tiras que elegimos de una persona,
    debemos recorrer linealmente desde el final y poniendo topes según lo hayamos marcado durante
    la DP.

    A considerar:
    Hacer una DP con la idea es fácil. Tal vez darse cuenta es difícil (llegué a esta solución después
    de estar horas viendo cómo funcionaba el código del usuario Zylber). Pero se aprende que
    sabiendo de tomar los rangos de la forma descrita, se puede. Pero dicha forma requiere una forma
    de reconstruir particular.
    Iremos como antes dijimos, linealmente fijándome los padres de mi posición, cambiando de banda
    cada tanda como lo hicimos en la DP. Muy importante ver cómo cambio de tanda, y hacerlo justo en
    el límite, pero que quede dicho en la otra tanda, ya que es el tope del primer elemento cuando
    cambié.
    Y otra consideración es rechequear la condición de poder ir de uno a otro, ya que si bien el
    camino está bien, se nos perdió parcialmente la información de por dónde fuimos y dónde no.

    Dado todo esto, fijarse de realizar específicamente la salida con espacios y enter al final
    delicadamente. Estuve 2 horas preguntándome porque al cambiar cosas no cambiaba el puntaje :/
*/

rango pedidos[MAXN];
int dp[MAXN][2]; int P[MAXN][2];

int main() {
    freopen("mercachifle.in","r",stdin); // input
    freopen("mercachifle.out","w",stdout); // output (OJO, SÚPER ESTRICTO)

    int A,B;
    // guardamos pedidos con un margen para dejar un pedido dummy al principio, del cual partir
    scanf("%d",&A);
    forn (i,A) {scanf("%d %d",&pedidos[i+1].l,&pedidos[i+1].r); pedidos[i+1].id = i+1; pedidos[i+1].A = false;}
    scanf("%d",&B);
    forn (i,B) {scanf("%d %d",&pedidos[A+i+1].l,&pedidos[A+i+1].r); pedidos[A+i+1].id = i+1; pedidos[A+i+1].A = true;}

    forn (i,MAXN) forn (j,2) P[i][j] = -1; // reset

    sort(pedidos,pedidos+A+B+1); // ordeno (A+B+dummy)

    forn (i,A+B+1) {
        int onWay[2] = {0,0}; // cuantos puedo en tira actual de persona i
        forsn (j,i+1,A+B+1) {
            if (pedidos[j].l > pedidos[i].r) // si puedo ir a i a j, sumo
                onWay[pedidos[j].A]++;

            forn (k,2)
                if (dp[j][k] < dp[i][!k]+onWay[k]) {
                    dp[j][k] = dp[i][!k]+onWay[k]; // marco mi camino hasta el punto, el quiebre lo determina el !k (paso de una banda de la DP a la otra)
                    P[j][k] = i; // voy sumando pedidos con onWay, por lo que con padres se que siempre corto,y me preocupo nada más de los índices
                }
        }
    }

    vi r[2];
    bool state = (max(dp[A+B][0],dp[A+B][1]) == dp[A+B][0] ? false : true);
    cout << max(dp[A+B][0],dp[A+B][1]) << endl; // Después me puede cambiar los estados, así que lo devuelvo ahora

    // let's reconstruct!
    int limit = P[A+B][state]; // empezando desde el padre
    dforn (i,A+B+1) { // volviendo desde atrás

        if (i == limit) { // me establezco un tope, si llego, lo actualizo para atrás
            state = !state;
            limit = P[i][state];
        }

        if (pedidos[i].A == state and pedidos[i].l > pedidos[limit].r) // perdí información, reviso el chequeo para reconstruir bien
            r[state].pb(pedidos[i].id);
    }

    forn (i,2) { // OUTPUT ROTÍSIMO MUY ESTRICTO CON ENTER Y ESPACIOS
        forn (j,r[i].size()) {
            if (j) printf(" ");
            printf("%d",r[i][j]);
        }
        puts("");
        fflush(stdout);
    }

    return 0;
}
