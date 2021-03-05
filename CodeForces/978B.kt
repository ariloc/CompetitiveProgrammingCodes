fun main() {
    val n = readLine()!!.toInt()
    var s : String = readLine()!!
    s += 'a' // dummy
    var (cnt,rta) = listOf(0,0)
    for (i in s)
        if (i != 'x') {rta += kotlin.math.max(0,cnt-2); cnt = 0;}
        else cnt++;
    print("$rta")
} 
