fun main() {
    val t = readLine()!!.toInt();
    for (i in 0..t-1) {
        val n = readLine()!!.toInt();
        val arr = readLine()!!.split(" ").map{it.toInt();}
        val rta = arrayListOf<Int>();

        var mini = 105;
        var cnt = 0;
        for (i in 0..n-1) {
            if (arr[i] >= mini) {
                rta.add(i+1);
                cnt++;
            }
            mini = kotlin.math.min(arr[i],mini);
        }

        println("$cnt");
        rta.forEach { x -> 
            print("$x ");
        }
        println("");
    }
}
