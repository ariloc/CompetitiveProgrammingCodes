const val MAXN = 200005

var dpR = IntArray(MAXN) {i -> 0}
var dpL = IntArray(MAXN) {i -> 0}
var posic = IntArray(MAXN) {i -> 0}
var mode = IntArray(MAXN) {i -> 0}

fun main() {
    val q = readLine()!!.toInt()
    var (l,r) = arrayOf(0,0);
    for (i in 0..q-1) {
        var (c,idS) = readLine()!!.split(" ")
        val id = idS.toInt()
        
        if (c == "L") {l++; posic[id] = i+1;}
        else if (c == "R") {r++; posic[id] = i+1; mode[id] = 1;}
        
        dpL[i+1] = l; dpR[i+1] = r;
        
        if (c == "?") { // molestos mini desfases que por apurado ni pienso
            if (mode[id] > 0) println("${kotlin.math.min(dpR[posic[id]-1] + l, r - dpR[posic[id]])}");
            else println("${kotlin.math.min(l - dpL[posic[id]], dpL[posic[id]-1] + r)}");
        }
    }
} 
