class Queue():
	def __init__(self, length):
		self.data = [0] * length
		self.head = 0
		self.tail = 0
		self.length = length

	def put(self, element):
		self.data[self.tail] = element
		if self.tail == self.length - 1:
			self.tail = 0
		else:
			self.tail += 1

	def get(self):
		x = self.data[self.head]
		if self.head == self.length - 1:
			self.head = 0
		else:
			self.head += 1
		return x

queue = Queue(1000000)

inputf = list(open("quack.in"))
outputf = open("quack.out", "w")
com = 0
registers = [0] * 26;
lables = {}

for i in range(len(inputf)):

	if inputf[i][-1:] == "\n":
		inputf[i] = inputf[i][:-1]

	if inputf[i][0] == ":":
		mark = inputf[i][1:]
		lables[mark] = i

while (com < len(inputf)):

	if inputf[com][0] == "+":
		res = queue.get() + queue.get()
		queue.put(res % 65536)

	elif inputf[com][0] == "-":
		res = queue.get() - queue.get()
		queue.put(res % 65536)

	elif inputf[com][0] == "*":
		res = queue.get() * queue.get()
		queue.put(res % 65536)

	elif inputf[com][0] == "/":
		x = queue.get()
		y = queue.get()
		if y != 0:
			queue.put(x // y % 65536)
		else:
			queue.put(0)

	elif inputf[com][0] == "%":
		x = queue.get()
		y = queue.get()
		if y != 0:
			queue.put(x % y % 65536)
		else:
			queue.put(0)

	elif inputf[com][0] == ">":
		char = inputf[com][1]
		registers[ord(char) - 97] = queue.get()

	elif inputf[com][0] == "<":
		char = inputf[com][1]
		queue.put(registers[ord(char) - 97])

	elif inputf[com][0] == "P" and len(inputf[com]) == 1:
		outputf.write(str(queue.get()) + "\n")

	elif inputf[com][0] == "P" and len(inputf[com]) == 2:
		char = inputf[com][1]
		outputf.write(str(registers[ord(char) - 97]) + "\n")

	elif inputf[com][0] == "C" and len(inputf[com]) == 1:
		outputf.write(chr(queue.get() % 256))

	elif inputf[com][0] == "C" and len(inputf[com]) == 2:
		char = inputf[com][1]
		outputf.write(chr(registers[ord(char) - 97] % 256))

	elif inputf[com][0] == "J":
		mark = inputf[com][1:]
		com = lables[mark] - 1

	elif inputf[com][0] == "Z":
		char = inputf[com][1]
		mark = inputf[com][2:]
		if registers[ord(char) - 97] == 0:
			com = lables[mark] - 1

	elif inputf[com][0] == "E":
		char1 = inputf[com][1]
		char2 = inputf[com][2]
		mark = inputf[com][3:]
		if registers[ord(char1) - 97] == registers[ord(char2) - 97]:
			com = lables[mark] - 1

	elif inputf[com][0] == "G":
		char1 = inputf[com][1]
		char2 = inputf[com][2]
		mark = inputf[com][3:]
		if registers[ord(char1) - 97] > registers[ord(char2) - 97]:
			com = lables[mark] - 1

	elif inputf[com][0] == "Q":
		break

	elif inputf[com][0] == ":":
		com += 1
		continue

	else:
		queue.put(int(inputf[com]) % 65536)

	com += 1

outputf.close()