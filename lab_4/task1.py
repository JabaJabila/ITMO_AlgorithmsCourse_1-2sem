class Stack():
	def __init__(self, length):
		self.data = [0] * length
		self.top = 0

	def push(self, element):
		self.data[self.top] = element
		self.top += 1

	def pop(self):
		self.top -= 1
		return self.data[self.top]

mystack = Stack(1000000)

inputf = list(open("stack.in"))
outputf = open("stack.out", "w")
n = int(inputf[0])

for i in range(1, n + 1):
	command = inputf[i].split()
	if command[0] == "+":
		num = int(command[1])
		mystack.push(num)
	if command[0] == "-":
		outputf.write(str(mystack.pop()) + "\n")