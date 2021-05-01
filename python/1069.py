n = int(input())

msj = ""

cases = list()
res = list()

for i in range(n):
	case = input()
	cases.append(case)

for i in range(len(cases)):
	case = cases[i]
	cont = 0
	j = 0
	ini = -1
	while j < len(case):
		if case[j] == "<":
			ini = j
		elif case[j] == ">":
			if ini != -1:
				if j < len(case) - 1:
					case = case[: ini] + case[j + 1: ]
				else:
					case = case[: ini]
				ini = -1
				j = -1
				cont += 1
		j += 1
	res.append(cont)

for i in range(len(res)):
	print(res[i])