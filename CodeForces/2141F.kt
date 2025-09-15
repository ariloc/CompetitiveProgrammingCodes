fun main() {
    val t = readln().toInt()
    for (_i in 0..<t) {
        val n = readln().toInt()
        val arr = readln().split(" ").map { it.toInt() }.sorted()

        val groups = mutableListOf<Int>()

        var cnt = 1
        for (i in 1 ..< n) {
            if (arr[i] != arr[i-1]) {
                groups.add(cnt)
                cnt = 0
            }
            cnt++
        }
        groups.add(cnt)
        groups.sort()

        val rta = MutableList(n) { 0 }
        val auxi = kotlin.math.min(groups.max(), groups.size)
        for (i in 0..<n)
            rta[i] = auxi

        val pref = MutableList(n+1) {0}
        val maxids = MutableList(n+1){-1}
        for (i in 0..<groups.size) {
            pref[groups[i]] += groups[i]
            maxids[groups[i]] = kotlin.math.max(maxids[groups[i]],i)
        }
        for (i in 1..n) {
            pref[i] += pref[i-1]
            maxids[i] = kotlin.math.max(maxids[i],maxids[i-1])
        }

        var acc = 0
        rta.add(-1) // dummy
        for (i in (0..<groups.size).reversed()) {
            for (j in 0..groups[i]) {
                val todel = acc + pref[j] + (i-maxids[j])*j
                rta[n-todel] = kotlin.math.min(rta[n-todel], j+(groups.size-i-1))
            }

            acc += groups[i]
        }

        for (i in 1..<n)
            rta[i] = kotlin.math.min(rta[i], rta[i-1])
        for (i in 0..<n) { print("${rta[i]} ") }
        println()
    }
}
