result = list()
cases = list()
flag = True
while flag:
	x = int(input())
	if x == 0:
		flag = False
	else:
		cases.append(x)
		
for i in range(len(cases)):
	case = cases[i]
	res = 0
	if case % 2 == 0:
		caseTemp = case
	else:
		caseTemp = case + 1

	res = caseTemp
	res += caseTemp + 2
	res += caseTemp + 4
	res += caseTemp + 6
	res += caseTemp + 8

	result.append(res)

for i in range(len(result)):
	print(result[i])