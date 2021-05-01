def main():
	b=list()
	a=input()
	mayor = 0
	pos = 0
	for i in range(len(a)):
		if(a[i]==" " or i==(len(a)-1)):
			if(i==(len(a)-1)):
				b.append(int(a[pos:i+1]))
			else:
				b.append(int(a[pos:i]))
			pos = i
	print(str(usarFormula(b, 1, 0))+" eh o maior")

def usarFormula(b, pos, mayor):
	if(pos==(len(b)-1)):
		return int((mayor+b[pos]+abs(mayor-b[pos]))/2)
	else:
		if(pos==1):
			mayor=int((b[pos-1]+b[pos]+abs(b[pos-1]-b[pos]))/2)
		else:
			mayor=int((mayor+b[pos]+abs(mayor-b[pos]))/2)
		return usarFormula(b, pos+1, mayor)


if __name__ == '__main__':
	main()