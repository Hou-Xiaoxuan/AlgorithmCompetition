'''
Author: LinXuan
Date: 2021-12-19 16:32:21
Description: 
LastEditors: LinXuan
LastEditTime: 2021-12-19 17:42:26
FilePath: /Algorithm/algorithm_contest/Others/12_19_传智杯/B.py
'''

for i in range(1, 30):
    a = []
    for j in range(1, i):
        a.append(i^j)
    print(i)
    print(str(bin(i)))
    print("", list(range(1, i)))
    print("", a)
    a.sort()
    print("", a)

# for i in range(1, 30):
#     s = str(bin(i))[2:][::-1]
#     a = 2**(len(s)) - i - 1         # 右边数字个数
#     b = 0
#     for j in range(0, len(s)):
#         if s[j] == '1':
#             b += 2**(j+1) - 2**(j)
#     b = b - (2**(len(s))-i)
#     print(i, " : ", a, " ", b)
