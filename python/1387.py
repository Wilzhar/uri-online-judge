while True:
	sons = input().split(" ")
	sonsL = int(sons[0])
	sonsR = int(sons[1])
	if sonsL == 0 and sonsR == 0:
		break
	else:
		print(sonsL + sonsR)