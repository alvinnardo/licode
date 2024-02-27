# 标记 10**5 以内的质数
MX = 10 ** 5 + 1
is_prime = [True] * MX
is_prime[1] = False
for i in range(2, isqrt(MX) + 1):
  if is_prime[i]:
    for j in range(i * i, MX, i):
	is_prime[j] = False
