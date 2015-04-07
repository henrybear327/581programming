from random import randint

f_input = open('my_input.txt', 'w')
f_output = open('my_output.txt', 'w')

f_input.write('100\n')
for _ in range(100):
	a = randint(1, 2**10)
	b = randint(1, 2**10)
	c = randint(1, 10000)
	f_input.write('{} {} {}\n'.format(a, b, c))
	f_output.write(str(a**b % c) + '\n')

f_input.close()
f_output.close()