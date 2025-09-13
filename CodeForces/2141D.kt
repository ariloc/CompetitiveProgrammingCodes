fun main() {
    val t = readln().toInt()
    for (_i in 0..<t) {
        val par = readln().split(" ")
        val n = par[0].toInt()
        val k = par[1].toLong()
        val arr = readln().split(" ").map { it.toInt() }

        val coins: Long = 0
        val mini = arr.min()
        val maxi = arr.max()

        var acc: Long = 0
        for (i in 0..<n)
            acc += maxi - arr[i]

        if (acc > k) {
            println("-1")
        }
        else {
            if (mini != maxi) {
                var op: Long = 0
                var cntMini = 0
                for (i in 0..<n) {
                    if (arr[i] != mini)
                        op += maxi - arr[i]
                    else cntMini++
                }
                op += (cntMini - 1) * (maxi - mini - 1)

                val rem = k - acc
                val addi: Long = (rem / n).toLong() * (n - 1)
                println("${op + addi}")
            }
            else {
                val times:Long = (k/n)
                if (times == 0L) {
                    println("0")
                }
                else {
                    println("${(n-1).toLong()*(times-1)}")
                }
            }
        }
    }
}
