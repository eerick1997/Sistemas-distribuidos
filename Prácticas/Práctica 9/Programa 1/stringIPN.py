from random import randint
bigString = ""
n = int(input("Ingrese un numero: "))
for i in range(n):
    preString = ""
    for i in range(3):
        letra = str(chr(randint(65, 90)))
        preString += letra
    preString += " "
    bigString += preString

count = bigString.count("IPN")
print("La palabra IPN aparece {} veces".format(count))