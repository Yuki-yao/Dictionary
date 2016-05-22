# make_dictionary.py
input = open('englishdictionary.sql', 'r')
output = open('firststep', 'w')
for i in range(61):
	str = input.readline()
	if(i >= 45):
		v0 = str.split('),(')
		for j in range(len(v0)):
			if(j!=0):
				v1 = v0[j].split('\',\'')
				for k in range(len(v1)):
					if(k <= 2):
						s = v1[k]
						s = s.lstrip('\'')
						s = s.rstrip('\'')
						s = s.replace('\\n  ', '')
						s = s.replace('\\\"', '\"')
						s = s.replace('\\\'', '\'')
						s = s.replace('\');\n', '')
						output.write(s+'\n')	
				output.write('\n')		
