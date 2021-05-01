import math
v = float(input())
v = float('%.4f' % v)
for i in range(100):
	print("N["+str(i)+"] =", '%.4f' % (v/math.pow(2, i)))
