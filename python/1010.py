def main():
	entrada1 = input()
	entrada2 = input()
	salida1  = descomponerEntrada(entrada1)
	salida2  = descomponerEntrada(entrada2)

	print("VALOR A PAGAR:", "R$", '%.2f' % ((int(salida1[1])*float(salida1[2]))+(int(salida2[1])*float(salida2[2]))))

def descomponerEntrada(entrada):
	pos = 0
	ind = 0
	salida = [0 for i in range(3)]
	for i in range(len(entrada)):
		if(ind==2):
			salida[ind] = entrada[pos: ]
		else:
			if(entrada[i]==" "):
				salida[ind] = entrada[pos: i]
				pos = i+1
				ind+=1
	return salida

if __name__ == '__main__':
	main()
