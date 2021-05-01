def main():
	num = int(input())
	numBilletes = [0, 0, 0, 0, 0, 0, 0]
	billetes = [100, 50, 20, 10, 5, 2, 1]
	descomponerBilletes(num, billetes, 0, numBilletes)
	print(num)
	for i in range(len(billetes)):
		print(numBilletes[i], "nota(s) de R$", str(billetes[i])+",00")


def descomponerBilletes(num, billetes, pos, numBilletes):
	if(pos!=len(billetes)):
		numBilletes[pos] = int(num/int(billetes[pos]))
		descomponerBilletes(num%billetes[pos], billetes, pos+1, numBilletes)


if __name__ == '__main__':
	main()