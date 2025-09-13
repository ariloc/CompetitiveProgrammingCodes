fun main() {
    val t = readLine()!!.toInt();
    for (_i in 0..t-1) {
        val (n,m) = readLine()!!.split(" ").map{it.toInt();}
        var a = readLine()!!.split(" ").map{it.toInt();}
        var b = readLine()!!.split(" ").map{it.toInt();}

        val likesA = a.toSet()
        val likesB = b.toSet()

        a = a.sortedBy { x ->
            if (likesB.contains(x))
                return@sortedBy x
            return@sortedBy -x
        }

        b = b.sortedBy { x ->
            if (likesA.contains(x))
                return@sortedBy x
            return@sortedBy -x
        }

        val used = mutableSetOf<Int>()
        var i = 0
        var j = 0
        var turn = false
        var sug = 0
        while (i < n && j < m) {
            if (!turn) {
                if (!used.contains(a[i])) {
                    sug++
                    used.add(a[i])
                    turn = true
                    if (likesB.contains(a[i]))
                        break
                }
                i++
            }
            else {
                if (!used.contains(b[j])) {
                    sug++
                    used.add(b[j])
                    turn = false
                    if (likesA.contains(b[j]))
                        break
                }
                j++
            }
        }
        println("$sug")
    }
}
