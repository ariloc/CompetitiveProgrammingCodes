fun posib(mid: Long, n: Long, s: Long) : Boolean {
    var myLog = 1L; 
    var sum = mid;
    var m = mid;
    while (m > 0) {
        if (sum > s) { // ojo si es mayor nada más, igual sigo
            if (myLog <= n) return false // si me paso sin haber cubierto todo (o que al terminar de cubrir se rompe) chau
            return true // de lo contrario great
        }
        
        m = (m+1)/2L; myLog++; sum += m;
        if (m == 1L) break; // CASO BORDE (oops), dividir sigue infinitamente porque hago un ceil
    }
    if (sum > s) {
        if (myLog <= n) return false;
        return true;
    }
    if (myLog >= n) return true // si no alcancé la suma pero si el n, nomás subiendo todo un poco zafo
    if (sum+(n-myLog) > s) return false // si al poner todo lo que me falta al mínimo me paso, significa que tengo que bajar un poco el tope
    return true // si llego de 10
}

fun main() {
    val t = readLine()!!.toInt()
    for (o in 0..t-1) {
       	val (n,s) = readLine()!!.split(" ").map {it.toLong();}
        
        var low = 1L; var high = s;
        while (high-low > 1) {
            val mid = low + (high-low)/2L;
            
            if (posib(mid,n,s)) low = mid;
            else high = mid;
        }
        
        if (posib(high,n,s)) low = high;
        print("$low\n")
    }
}
