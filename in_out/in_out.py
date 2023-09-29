num = input()
num = num.split('.')
num_1 = str(int(num[1]))
num_2 = num[0]
new_num = num_1 + '.' + num_2
print(new_num)