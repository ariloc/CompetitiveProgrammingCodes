fun main() {
    val t = readLine()!!.toInt()
    for (i in 0..t-1) {
       	val (x,y) = readLine()!!.split(" ").map {it.toInt()}
       	var k = 0L; var p = x*1000000000L; var cnt = 0L;
        while (p >= x) {
            var aux = (y-k)/p
            k += aux*p; p /= 10; cnt += aux;
        }
        if (k < y) cnt += y-k;
        println("$cnt");
    }
}
