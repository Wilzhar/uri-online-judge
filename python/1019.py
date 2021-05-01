n = int(input())
if n <= 60:
	h = 0
	m = 0
	s = n
elif n <= 3600:
	h = 0
	m = int(n / 60)
	s = int(n - (m * 60))
else:
	h = int(n / 3600)
	m = int((n - (h * 3600)) / 60)
	s = int((n - (h * 3600)) - (m * 60))
print(str(h) + ":" + str(m) + ":" + str(s))

