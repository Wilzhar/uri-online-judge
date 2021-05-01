import math

def main():
	dato1 = input()
	dato2 = input()
	punto1 = separarDatos(dato1)
	punto2 = separarDatos(dato2)
	distancia = math.sqrt(math.pow(punto2[0]-punto1[0], 2)+math.pow(punto2[1]-punto1[1], 2))
	print('%.4f' % distancia)

def separarDatos(datos):
	lista = list()
	pos = 0;
	for i in range(len(datos)):
		if(datos[i]==" " or i==(len(datos)-1)):
			if(i == (len(datos)-1)):
				lista.append(float(datos[pos:i+1]))
			else:
				lista.append(float(datos[pos:i]))
			pos=i
	return lista

if __name__ == '__main__':
	main()