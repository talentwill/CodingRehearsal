# 剑指 Offer 49. 丑数

L = [1]
n = 100

# 暴力解法，超时
for i in range(n):
	L.append(L[i] * 2)
	L.append(L[i] * 3)
	L.append(L[i] * 5)
	L = sorted(list(set(L)))

print(L[n-1])
