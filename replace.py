# This is just in the repository so I can double click it and run it
# without having to put in a bunch of directories. I should probably
# remove it or move it to root. 
# Give this input.txt and it will replace all tabs with 4 spaces. 
import sys
if len(sys.argv) == 1:
	if sys.version_info[0]<3:
		input = raw_input

	i = input("What is the input file, with extension? ")
	o = input("What will the output be, with extension? ")
elif len(sys.argv)==3:
	i = sys.argv[1]
	o = sys.argv[2]
else:
	raise Exception("You gave too many or too few arguments!")
with open(i, 'r')  as f:
	with open(o, 'a') as w:
		for j in f: 
			w.write(j.replace("\t", "    "))
