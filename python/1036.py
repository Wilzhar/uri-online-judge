import math

entrada = input().split(" ")

a = float(entrada[0])
b = float(entrada[1])
c = float(entrada[2])

if (b**2) > (4*a*c) and (a != 0):
	r1 = (-b + math.sqrt(b**2 - 4 * a * c)) / (2 * a)
	r2 = (-b - math.sqrt(b**2 - 4 * a * c)) / (2 * a)
	print("R1 =", "%.5f" % (r1))
	print("R2 =", "%.5f" % (r2))
else:
	print("Impossivel calcular")




