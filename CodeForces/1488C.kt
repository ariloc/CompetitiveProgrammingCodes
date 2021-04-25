const val INF = 1000000000;

fun main() {
    val t = readLine()!!.toInt()
    for (o in 0..t-1) {
       	var (n,x,y) = readLine()!!.split(" ").map {it.toInt();}
        if (x > y) x = y.also{y = x} // swap
        var rta = INF;
       	for (i in x..y-1) { // considerando que el primer policía hace el rango [1,i]
            val a = kotlin.math.min(x-1+ (if (i > x) (i-1) else 0), i-x+ (if (x > 1) (i-1) else 0));
            val b = kotlin.math.min(y-i-1+ (if(y < n) (n-i-1) else 0), n-y+ (if(i+1 < y) (n-i-1) else 0));
            rta = kotlin.math.min(rta,kotlin.math.max(a,b));
        }
        println("$rta");
    }
}
