import math

n = int(input())
res = list()

cases = list()
for i in range(n):
	case = input().split(" ")
	cases.append([case[0], case[1]])

for i in range(len(cases)):
	n = int(cases[i][0])
	m = int(cases[i][1])
	x = int(math.log10(n ** m)) + 1
	res.append(x)

for i in range(len(res)):
	print(res[i])

