from math import sin, cos, tan, log, sqrt
n = int(input("Ingrese un numero: "))
seno = 0
coseno = 0
tangente = 0
logaritmo = 0
raizCUadrada = 0
i = 1
while(i<n):
    seno+=sin(i)
    coseno+=cos(i)
    tangente+=tan(i)
    logaritmo+=log(i)
    raizCUadrada+=sqrt(i)
    i+=1
print("Seno: {}\nCoseno: {}\nTangente: {}\nLogaritmo: {}\nRaiz: {}\n".format(seno, coseno,tangente, logaritmo, raizCUadrada))