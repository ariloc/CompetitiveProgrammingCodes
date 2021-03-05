fun main() {
    val n = readLine()!!.toInt()
    val nums = readLine()!!.split(" ").map {it.toInt()}
    val rta = arrayListOf<Int>()
    for (i in n-1 downTo 0)
        if (!rta.contains(nums.get(i))) rta.add(nums.get(i))
    rta.reverse()
    println(rta.size)
    for (i in rta) print("$i ")
}
