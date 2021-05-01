def main():
	nums = [int(input()) for x in range(15)]
	imprimirPares(nums, 0, 0)

def imprimirPares(nums, pos, cont):
	if(len(nums)!=0):
		if(cont<5):
			if(nums[pos]%2==0):
				print("par["+str(cont)+"]","=",nums[pos])
				nums.pop(pos)
				imprimirPares(nums, pos-1, cont+1)
			else:
				if(pos==(len(nums)-1)):
					imprimirImpares(nums, 0, 0)
				else:
					imprimirPares(nums, pos+1, cont)
		else:
			imprimirImpares(nums, 0, 0)

def imprimirImpares(nums, pos, cont):
	if(len(nums)!=0):
		if(cont<5):
			if(nums[pos]%2!=0):
				print("impar["+str(cont)+"]","=",nums[pos])
				nums.pop(pos)
				imprimirImpares(nums, pos-1, cont+1)
			else:
				if(pos==(len(nums)-1)):
					imprimirPares(nums, 0, 0)
				else:
					imprimirImpares(nums, pos+1, cont)
		else:
			imprimirPares(nums, 0, 0)

if __name__ == '__main__':
	main() 
