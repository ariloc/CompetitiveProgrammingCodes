fun main() {
    val n = readLine()!!.toInt()
    val inst = arrayListOf<String>()
    for (i in 0..n-1) {
        if (i % 2 == 0) {
            for (j in i..n-1) {
                inst.add("pushback a[$j]")
                inst.add("min")
            }
            inst.add("popfront")
        }
        else {
            for (j in i..n-1) {
                inst.add("min")
                inst.add("popback")
            }
        }
    }
    println("${inst.size}")
    inst.forEach { println(it) }
}
