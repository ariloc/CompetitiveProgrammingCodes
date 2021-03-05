const val MAXN = 200005

var arr = IntArray(MAXN) {i -> 0}
var n = 0; var m = 0; var k = 0;

fun solve (st: Int) : Boolean {
    var (acc,boxes) = arrayOf(0,0)
    for (i in st..n-1) {
        if (acc+arr[i] > k) {boxes++; acc = 0;}
        acc += arr[i];
    }
    if (acc > 0) boxes++;
    return (boxes <= m);
}

fun main() {
    val (nn,mm,kk) = readLine()!!.split(" ").map {it.toInt();}
    n = nn; m = mm; k = kk;
    val inp = readLine()!!.split(" ").map {it.toInt();}
    for (i in 0..n-1) arr[i] = inp[i]; // lo copio global por comodidad
    
    var (low,high) = arrayOf(0,n-1);
    while (high-low > 1) {
        val mid = (high+low)/2;
        
        if (solve(mid)) high = mid;
        else low = mid;
    }
    
    if (solve(low)) high = low;
    
    print("${n-high}");
}
