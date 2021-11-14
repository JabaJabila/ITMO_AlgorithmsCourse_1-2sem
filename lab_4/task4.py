class Stack():
	def __init__(self, length):
		self.data = [0] * length
		self.top = 0
		self.length = length

	def push(self, element):
		self.data[self.top] = element
		self.top += 1

	def pop(self):
		self.top -= 1
		return self.data[self.top]

mystack = Stack(100)

inputf = list(open("postfix.in"))
outputf = open("postfix.out", "w")
a, b = 0, 0

for i in inputf[0][:-1]:

	if i == " ":
		continue

	if i == "+":
		a = mystack.pop()
		b = mystack.pop()
		mystack.push(a + b)

	elif i == "-":
		a = mystack.pop()
		b = mystack.pop()
		mystack.push(b - a)

	elif i =="*":
		a = mystack.pop()
		b = mystack.pop()
		mystack.push(a * b)

	else:
		mystack.push(int(i));

outputf.write(str(mystack.pop()))