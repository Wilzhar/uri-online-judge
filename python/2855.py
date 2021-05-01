def main():
	tamanio = int(input())
	secuencia= list()
	for i in range(tamanio):
		secuencia.append(int(input()))
	num = int(input())
	if isLucky(secuencia, num, 1):
		print("Y")
	else:
		print("N")

def isLucky(secuencia, num, pos):
	if secuencia[pos]>num:
		return binarySearch(secuencia, num)
	else:
		i=0
		while pos+i<len(secuencia):
			secuencia.pop(pos+i)
			i+=pos
		return isLucky(secuencia, num, pos+1)

def binarySearch(arreglo, numBusqueda):
	if len(arreglo)==1:
		if arreglo[0]==numBusqueda:
			return True
		else:
			return False
	else:
		if arreglo[int(len(arreglo)/2)]>numBusqueda:
			return binarySearch(arreglo[:int(len(arreglo)/2)], numBusqueda)
		else:
			return binarySearch(arreglo[int(len(arreglo)/2):], numBusqueda)

if __name__ == '__main__':
	main()