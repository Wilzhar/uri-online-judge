def main():
	inPut=int(input())
	outPut=list()
	array= list()
	for i in range(inPut):
		array.append(input())

	for i in range(len(array)):
		lista=separarNumerosLinea(array[i])
		if(lista[0]>=lista[1]):
			outPut.append(isEncajar(lista[0], lista[1], True))
		else:
			outPut.append("nao encaixa")
	for i in range(len(outPut)):
		print(outPut[i])


def isEncajar(a, b, cent):
	if(b<10 or cent==False):
		if(cent):
			if(int(b%10)==int(a%10)):
				return "encaixa"
			else:
				return "nao encaixa"
		else:
			return "nao encaixa"
	else:
		if(int(b%10)==int(a%10)):
			return isEncajar(a/10, b/10, True)
		else:
			return isEncajar(a/10, b/10, False)

	
def separarNumerosLinea(palabra):
	lista=list()
	pos=0
	for i in range(len(palabra)):
		if(palabra[i]==" " or i==(len(palabra)-1)):
			if(i==(len(palabra)-1)):
				lista.append(int(palabra[pos:i+1]))
			else:
				lista.append(int(palabra[pos:i]))
			pos=i
	return lista

if __name__ == '__main__':
	main()