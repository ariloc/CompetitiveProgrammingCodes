n,m = map(int,input().split())
arr = list(map(int,input().split()))

on = 0

state = 1
prv = 0
for i in range(n):
    if state:
        on += arr[i]-prv
    state ^= 1
    prv = arr[i]
    
if state:
    on += m - arr[-1]

nxt = m
accOff = 0
accOn = 0
maxi = on
for i in range(n-1,-1,-1):
    if state:
        accOn += nxt-(arr[i]+1)
    else:
        accOff += nxt-(arr[i]+1)
    
    if arr[i]+1 < m and (i == n-1 or arr[i]+1 < arr[i+1]):
        maxi = max(maxi, on - accOn + accOff)

    if state:
        accOn += 1
    else:
        accOff += 1
    
    if arr[i]-1 > 0 and (i == 0 or arr[i]-1 > arr[i-1]):
        if state:
            maxi = max(maxi, on - accOn + (accOff+1))
        else:
            maxi = max(maxi, on - (accOn+1) + accOff)

    nxt = arr[i]
    state ^= 1

print(maxi)
