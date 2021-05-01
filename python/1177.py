num = int(input())
cont=0
for i in range(1000):
	if(cont==num):
		cont=0
	print("N["+str(i)+"]","=", cont)
	cont=cont+1