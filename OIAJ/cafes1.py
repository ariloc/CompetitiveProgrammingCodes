INF = 1000000000

def cafes(nombres, precios, distancias):
    N = len(nombres)
    mini = INF
    minip = INF
    idx = -1
    for i in range(N):
        c = precios[i] * distancias[i]
        if c < mini:
            mini = c
            minip = precios[i]
            idx = i
        elif c == mini and precios[i] < minip:
            minip = precios[i]
            idx = i

    return nombres[idx]
