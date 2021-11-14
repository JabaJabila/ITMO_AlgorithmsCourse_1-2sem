class Queue():
	def __init__(self, length):
		self.data = [0] * length
		self.head = 0
		self.tail = 0
		self.length = length

	def enqueue(self, element):
		self.data[self.tail] = element
		if self.tail == self.length - 1:
			self.tail = 0
		else:
			self.tail += 1

	def dequeue(self):
		x = self.data[self.head]
		if self.head == self.length - 1:
			self.head = 0
		else:
			self.head += 1
		return x

myqueue = Queue(1000000)

inputf = list(open("queue.in"))
outputf = open("queue.out", "w")
n = int(inputf[0])

for i in range(1, n + 1):
	command = inputf[i].split()
	if command[0] == "+":
		num = int(command[1])
		myqueue.enqueue(num)
	if command[0] == "-":
		outputf.write(str(myqueue.dequeue()) + "\n")