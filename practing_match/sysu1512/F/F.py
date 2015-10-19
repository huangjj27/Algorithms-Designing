# Copyright (c) 2015 HuangJunjie@SYSU(SNO:13331087). All Rights Reserved.
# original from http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=27826
import sys

num = sys.stdin.readline()
n = int(num)
result = n % 3
n -= result

if (result <= 1 and n > 1):
  result += 3
  n -= 3

while n:
  result *= 3
  n -= 3

print result
