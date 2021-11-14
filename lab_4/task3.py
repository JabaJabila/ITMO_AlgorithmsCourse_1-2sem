class Stack():
	def __init__(self, length):
		self.data = [0] * length
		self.top = 0
		self.length = length

	def is_empty(self):
		if self.top == 0:
			return True
		return False

	def push(self, element):
		self.data[self.top] = element
		self.top += 1

	def pop(self):
		self.top -= 1
		return self.data[self.top]

	def clean(self):
		self.top = 0


mystack = Stack(10000)

inputf = list(open("brackets.in"))
outputf = open("brackets.out", "w")

for string in inputf:
	check = True
	mystack.clean()
	for i in string:

		if i == "\n":
			continue
			
		if i == "(" or i == "[":
			mystack.push(i)
			
		elif not mystack.is_empty():

			if mystack.data[mystack.top - 1] == "(" and i == ")":
				mystack.pop()

			elif mystack.data[mystack.top - 1] == "[" and i == "]":
				mystack.pop()

			else:
				check = False
				break;

		else:
			check = False
			break;

	if not mystack.is_empty():
		check = False

	outputf.write("YES\n" if check else "NO\n")
