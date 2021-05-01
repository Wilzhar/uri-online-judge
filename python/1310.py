def main():
	while True:
		nDias = int(input())
		costoManteniminentoDia = int(input());
		revenuePerDay = [int(input()) for x in range(nDias)]
		print(calcularMayorIngreso(costoManteniminentoDia, revenuePerDay, 0, 0))
	archivo.close()

def calcularMayorIngreso(costoManteniminentoDia, revenuePerDay, pos, mayor):
	if pos >= len(revenuePerDay):
		return mayor
	else:
		for j in range(len(revenuePerDay)):
			cont = 0
			temp = 0
			for i in range(pos, len(revenuePerDay) - j, 1):
				temp += revenuePerDay[i]
				cont += 1

			temp = temp - (costoManteniminentoDia * cont)
			if temp > mayor:
				mayor = temp

		return calcularMayorIngreso(costoManteniminentoDia, revenuePerDay, pos + 1, mayor)

if __name__ == '__main__':
	main()
