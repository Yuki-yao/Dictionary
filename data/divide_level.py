input = open('word_frequency', 'r')
for i in range(20):
    j = 19-i
    j = j.__str__()
    output = open('level'+j+'.dat', 'w')
    for j in range(800):
	str = input.readline()
	output.write(str)

