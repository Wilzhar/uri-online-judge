lectura = open("1875R.txt", "r")
escritura = open("1875W.txt", "w")
#cases = int(input())
cases = int(lectura.readline())
for i in range(cases):
	#goals = int(input())
	goals = int(lectura.readline())
	rgbGoals = [0, 0, 0]
	for j in range(goals):
		#gol = input().split(" ")
		gol = lectura.readline().split(" ")
		gol[0] = gol[0][0]
		gol[1] = gol[1][0]
		if (gol[0] == "R" and gol[1] == "G") or (gol[0] == "G" and gol[1] == "B") or (gol[0] == "B" and gol[1] == "R"):
			switcher = {
				"R" : 0,
				"G" : 1,
				"B" : 2
			}
			pos = switcher.get(gol[0], -1)

			if pos != -1:
				rgbGoals[pos] += 2
		else:
			switcher = {
				"R" : 0,
				"G" : 1,
				"B" : 2
			}
			pos = switcher.get(gol[0], -1)

			if pos != -1:
				rgbGoals[pos] += 1
	if rgbGoals[0] == rgbGoals[1] and rgbGoals[0] == rgbGoals[2]:
		#print("trempate")
		escritura.write("trempate\n")
	elif (rgbGoals[0] == rgbGoals[1] and rgbGoals[0] > rgbGoals[2]) or (rgbGoals[0] == rgbGoals[2] and rgbGoals[0] > rgbGoals[1]) or (rgbGoals[1] == rgbGoals[2] and rgbGoals[1] > rgbGoals[0]):
		#print("empate")
		escritura.write("empate\n")
	else:
		if rgbGoals[0] > rgbGoals[1] and rgbGoals[0] > rgbGoals[2]:
			#print("red")
			escritura.write("red\n")
		elif rgbGoals[1] > rgbGoals[0] and rgbGoals[1] > rgbGoals[2]:
			#print("green")
			escritura.write("green\n")
		else:
			#print("blue")
			escritura.write("blue\n")
lectura.close()
escritura.close()