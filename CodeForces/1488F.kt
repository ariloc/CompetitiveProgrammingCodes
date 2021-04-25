const val MAXN = 200005
const val INF = 1000000000
var MAXST = (1 shl (32-MAXN.countLeadingZeroBits())) // __builtin_clz

data class segT (var v: Int, var ind: Int)

operator fun segT.plus(o: segT) : segT { // máximo con mín indice
   	if (o.v > this.v) return o;
    if (o.v == this.v) segT(o.v,minOf(o.ind,this.ind))
    return this;
}

val ST = Array<segT>(2*MAXST){segT(-1,-1)}
val arrG = IntArray(MAXN){0}
val dp = LongArray(MAXN){-1L}
val pMayorL = IntArray(MAXN){0}
var N = 0;

fun query (i: Int, tl: Int, tr: Int, bl: Int, br: Int) : segT {
    if (tl >= br || tr <= bl) return segT(-1,-1)
    if (tl >= bl && tr <= br) return ST[i];
    
    val mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br) + query(2*i+1,mid,tr,bl,br)
}

fun solve (i: Int) : Long {
    if (dp[i] != -1L) return dp[i];
    dp[i] = solve(pMayorL[i])+(i-pMayorL[i]).toLong()*arrG[i];
    return dp[i];
}

fun main() {
	val n = readLine()!!.toInt()
    val arr = readLine()!!.split(" ").map{it.toInt();}
    for (i in 0..n-1) arrG[i+1] = arr[i]; // lo copio por comodidad, 1 de desfase
    N = (1 shl (32-n.countLeadingZeroBits()));
    
    for (i in 0..n-1) ST[i+N].v = arr[i]; // copy values
    for (i in 0..N-1) ST[i+N].ind = i; // agrego inds
   	for (i in N-1 downTo 1) ST[i] = ST[2*i]+ST[2*i+1]; // build
    
    arrG[0] = INF; dp[0] = 0; // caso base está resuelto
    for (i in 1..n) { // primero mayor a mi derecha
        var idx = i-1;
        while (arrG[idx] <= arrG[i]) idx = pMayorL[idx];
        pMayorL[i] = idx;
    }
    
    for (i in 1..n) solve(i);
    
    val q = readLine()!!.toInt()
    for (i in 1..q) {
        val (l,r) = readLine()!!.split(" ").map{it.toInt();}
        var maxi = query(1,0,N,l-1,r); 
        print("${dp[r]-dp[maxi.ind+1]+maxi.v.toLong()*(maxi.ind-l+2)} ") // +1s a maxiInd para 1-indexed
    }
    
}
