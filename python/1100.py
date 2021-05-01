lectura = open("1100R.txt", "r")
escritura = open("1100W.txt", "w")
movimientos = [ [0, 3, 2, 3, 2, 3, 4, 5],
				[3, 2, 1, 2, 3, 4, 3, 4],
				[2, 1, 4, 3, 2, 3, 4, 5],
				[3, 2, 3, 2, 3, 4, 3, 4],
				[2, 3, 2, 3, 4, 3, 4, 5],
				[3, 4, 3, 4, 3, 4, 5, 4],
				[4, 3, 4, 3, 4, 5, 4, 5],
				[5, 4, 5, 4, 5, 4, 5, 6]]

while True:
	#case = input().split(" ")
	case = lectura.readline().split(" ")
	if len(case) == 1:
		break;
	else:
		switcher = {
			"a": 1,
			"b": 2,
			"c": 3,
			"d": 4,
			"e": 5,
			"f": 6,
			"g": 7,
			"h": 8
			}
		ini = [switcher.get(case[0][0], -1), int(case[0][1])]
		fin = [switcher.get(case[1][0], -1), int(case[1][1])]
		if ini[0] != -1 and fin[0] != -1:
			deltaX = abs(fin[0] - ini[0])
			deltaY = abs(fin[1] - ini[1])
			case[1] = case[1][:len(case[1]) - 1]
			n = movimientos[deltaX][deltaY]
			if deltaX == 1 and deltaY == 1:
				if case[0] == "h1" or case[1] == "h1" or case[0] == "h8" or case[1] == "h8" or case[0] == "a1" or case[1] == "a1" or case[0] == "a8" or case[1] == "a8":
					n = 4
				else:
					n = 2
			msj = "To get from " + str(case[0]) + " to " + str(case[1]) + " takes " + str(n) + " knight moves.\n"
			escritura.write(msj)
		#print("To get from", case[0], "to", case[1], "takes", n, "knight moves.")

lectura.close()
escritura.close()



