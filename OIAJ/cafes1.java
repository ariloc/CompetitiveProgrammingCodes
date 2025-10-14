import java.lang.*;
import java.util.*;

public class cafes1 {
    public static final int INF = 1000000000;
    public static String cafes(ArrayList<String> nombres, ArrayList<Integer> precios, ArrayList<Integer> distancias) {
        int n = nombres.size();
        int mini = INF;
        int minip = INF;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            int prod = precios.get(i) * distancias.get(i);
            if (prod < mini) {
                mini = prod;
                minip = precios.get(i);
                idx = i;
            }
            else if (prod == mini && precios.get(i) < minip) {
                minip = precios.get(i);
                idx = i;
            }
        }
        return nombres.get(idx);
    }
}
