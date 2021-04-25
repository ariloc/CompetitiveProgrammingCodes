fun main() {
    val t = readLine()!!.toInt()
    for (i in 0..t-1) {
       	var(n,k) = readLine()!!.split(" ").map {it.toInt();}
        val s = readLine()!!
        
        val prefs = arrayListOf<Int>();
        var (cntO,cntC) = arrayOf(0,0);
        for (j in s) {
            if (j == '(') cntO++;
            else cntC++;
            if (cntC == cntO) {prefs.add(cntC+cntO); cntC = 0; cntO = 0;}
        }
        
        var rta = 0;
        for (j in prefs) {
            if (k <= 0) break;
            val use = kotlin.math.min((j-2)/2,k);
            k -= use; rta += use;
        }
        rta += prefs.size;
        
        println("$rta");
    }
}
