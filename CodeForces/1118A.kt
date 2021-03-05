fun main() {
    val n = readLine()!!.toInt()
    for (i in 1..n) {
        var (n,a,b) = readLine()!!.split(" ").map {it.toLong()}
        b = kotlin.math.min(b,a*2)
        println("${n/2*b + (n%2)*a}")
    }
} 
