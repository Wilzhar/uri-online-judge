def main():
	numEmp = input()
	numHoras = int(input())
	montonHora = float(input())

	salary = str(numHoras*montonHora)
	print("NUMBER = "+str(numEmp))
	print("SALARY = U$ "+fijarNumeroDecimas(salary[:salary.find(".")+3]))
	print()
	print()

def fijarNumeroDecimas(decimal):
	if(len(decimal[decimal.find(".")+1:len(decimal)])<2):
		return decimal+"0"
	else:
		return decimal

if __name__ == '__main__':
	main()