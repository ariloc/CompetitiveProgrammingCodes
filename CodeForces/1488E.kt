const val MAXN = 250005

var LIS = IntArray(MAXN){0};
var dp = IntArray(MAXN){0};
var nxt = IntArray(MAXN){0};

fun lower_bound(arr: IntArray, l: Int, r: Int, x: Int) : Int { // [l,r)
    var low = l; var high = r;
    while (high-low > 1) {
        var mid = (high+low)/2;
        
        if (arr[mid] >= x) high = mid;
        else low = mid;
    }
    if (arr[low] >= x) high = low;
    return high; // devuelve índice del mayor o igual, así que si se pasa del array, devuelve r, justo como quiero
}

fun main() {
    val t = readLine()!!.toInt();
    for (o in 0..t-1) {
       	val n = readLine()!!.toInt();
        val arr = readLine()!!.split(" ").map{it.toInt();}
            
		for (i in 0..n+2) {LIS[i] = -1; nxt[i] = -1;} // reset
        for (i in arr) dp[i] = -1; // como es por elementos, lo reseteo recorriendo los que hay en el array nada más
        
        for (i in n-1 downTo 0) {nxt[i] = dp[arr[i]]; dp[arr[i]] = i;} // ubicación próx de c/u, si la hay
        //for (i in 0..n-1) println("$i ${nxt[i]}");
        
        var rta = 1;
        
        var lis_nd = 0;
        for (i in n-1 downTo 0) {
            if (nxt[i] == -1) continue;
            val pos = lower_bound(LIS,0,lis_nd,nxt[i]);
            LIS[pos] = nxt[i];
            if (pos+1 > lis_nd) lis_nd = pos+1;
            //println("$i $pos $lis_nd")
        }
        rta = maxOf(rta,lis_nd*2)
        
        // voy a forzar a que el primer elemento si o si tenga un espacio
        lis_nd = 0;
        for (i in 0..n+2) LIS[i] = -1; // reset back again
        for (i in n-1 downTo 0) {
            if (nxt[i] == -1) continue;
            val pos = lower_bound(LIS,0,lis_nd,nxt[i]);
            if (nxt[i]-i <= 1) continue; // es creciente, así que no hace falta hacer check de posic
            LIS[pos] = nxt[i];
            if (pos+1 > lis_nd) lis_nd = pos+1;
        }
        
        rta = maxOf(rta,lis_nd*2+1)
        
        println("$rta");
        
    }
}
