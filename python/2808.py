entrada = input().split(" ")

initialPosition = entrada[0]
targetPosition = entrada[1]

colIni = ord(initialPosition[0]) - 96
rowIni = int(initialPosition[1])

colTarget = ord(targetPosition[0]) - 96
rowTarget = int(targetPosition[1])

msj = ""

if abs(colIni - colTarget) == 2:
	if abs(rowIni - rowTarget) == 1:
		msj = "VALIDO"
	else: 
		msj = "INVALIDO"
elif abs(colIni - colTarget) == 1:
	if abs(rowIni - rowTarget) == 2:
		msj = "VALIDO"
	else: 
		msj = "INVALIDO"
else:
	msj = "INVALIDO"

print(msj)
