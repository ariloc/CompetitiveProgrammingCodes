int suma(int a, int b)
{
    return a+b;
}

int producto(int a, int b)
{
    return a*b;
}

int paridadSuma(int a, int b)
{
    return suma(a,b)%2;
}


int selector(int op, int a, int b)
{
    if (op == 0) return suma(a,b);
    if (op == 1) return producto(a,b);
    return paridadSuma(a,b);
}
