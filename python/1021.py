def main():
	num = float(input())
	num = float('%.2f' % num)
	numBilletes = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	billetes = [100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25, 0.10, 0.05, 0.01]	
	descomponerBilletes(num, billetes, 0, numBilletes)
	print("NOTAS:")
	for i in range(len(billetes)):
		if(i == 6):
			print("MOEDAS:")
		if(i>=6):
			print(numBilletes[i], "moeda(s) de R$", '%.2f' % billetes[i])
		else:
			print(numBilletes[i], "nota(s) de R$", '%.2f' % billetes[i])

def descomponerBilletes(num, billetes, pos, numBilletes):
	if(pos!=len(billetes)):
		numBilletes[pos] = int(num/billetes[pos])
		descomponerBilletes(float('%.2f' % (num%billetes[pos])), billetes, pos+1, numBilletes)

if __name__ == '__main__':
	main()