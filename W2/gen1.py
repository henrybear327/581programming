from random import randint

f_input = open('my_input1.txt', 'w')
f_output = open('my_output1.txt', 'w')

f_input.write('100\n')
b = 0
for _ in range(100):
	a = 19
	b = b + 1
	c = 3021
	f_input.write('{} {} {}\n'.format(a, b, c))
	f_output.write(str(a**b % c) + '\n')

f_input.close()
f_output.close()
