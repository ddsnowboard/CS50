# Give this input.txt and it will replace all tabs with 4 spaces. 
import sys
if len(sys.argv)==1:
	if sys.version_info[0]<3:
		i = raw_input("What is the input file, with extension? ")
		o = raw_input("What will the output be, with extension? ")
	elif sys.version_info[0]>=3:
		i = input("What is the input file, with extension? ")
		o = input("What will the output be, with extension? ")
elif len(sys.argv)==3:
	i = sys.argv[1]
	o = sys.argv[2]
else:
	raise Exception("You gave too many arguments!")
with open(i, 'r')  as f:
	with open(o, 'a') as w:
		for j in f: 
			w.write(j.replace("\t", "    "))