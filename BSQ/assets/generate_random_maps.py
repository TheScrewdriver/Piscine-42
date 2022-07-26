import os
from random import randint, random

def generate_map(x, y, density):
	filename = f"maps/{x:02}_{y:02}_{round(density * 100):02}"
	with open(filename, "w") as fp:
		fp.write(f"{y}.ox\n")
		for i in range(y):
			for j in range(x):
				if (random() < density):
					fp.write("o")
				else:
					fp.write(".")
			fp.write("\n")


for _ in range(20):
	x = randint(1, 30)
	y = randint(1, 30)
	density = random()
	generate_map(x, y, density)