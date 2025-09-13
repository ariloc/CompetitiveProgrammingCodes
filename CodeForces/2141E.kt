const val MOD: Int = 998244353

fun binExp(a: Int, e: Int): Int {
    var r: Int = 1
    var b = a
    var k = e
    while (k > 0) {
        if (k and 1 == 1) {
            r = ((r * b.toLong()) % MOD).toInt()
        }
        b = ((b*b.toLong()) % MOD).toInt()
        k /= 2
    }
    return r
}

fun main() {
    val t = readln().toInt()
    for (_i in 0..<t) {
        val str: CharArray = readln().toCharArray()

        var cnt = str.count { c -> c == '?' }

        var r = 0
        if (str[0] == '1') {
            println(binExp(2,cnt))
            continue
        }
        else if (str[0] == '?') {
            if (str[1] == '0') {
                println(binExp(2,cnt))
                continue
            }
            else if (str[1] == '?') {
                cnt -= 2
                r = ((3L*binExp(2,cnt))%MOD).toInt()
                //str[0] = '0'
                //str[1] = '1'
            }
            else { // == 1
                cnt -= 1
                r = binExp(2,cnt)
                //str[0] = '0'
            }
        }
        else { // == 0
            if (str[1] == '0') {
                println(binExp(2,cnt))
                continue
            }
            else if (str[1] == '?') {
                cnt -= 1
                r = binExp(2,cnt)
                //str[1] = '1'
            }
            else { // == 1
                // nothing, idx = 2
            }
        }

        for (i in 2..<str.size) {
            if (str[i] == '0') {
                r = (r + binExp(2,cnt))%MOD
                break
            }
            if (str[i] == '?') {
                cnt -= 1
                r = (r + binExp(2,cnt))%MOD
            }
        }

        println("$r")
    }
}
