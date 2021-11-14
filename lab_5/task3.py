class Node:

	def __init__(self, key):

		self.left = None
		self.right = None
		self.key = key

def insert(root, key):

	if root == None:
		return Node(key)

	else:
		if root.key == key:
			return root

		elif root.key > key:
			root.left = insert(root.left, key)

		else:
			root.right = insert(root.right, key)

	return root

def search(root, key):

	if root == None:
		return None

	elif root.key == key:
		return root.key

	elif root.key > key:
		return search(root.left, key)
   
	else:
		return search(root.right, key)	

def exists(root, key):

	return "true" if search(root, key) else "false"

def min_node(root):

    tmp = root

    while(tmp.left != None):
        tmp = tmp.left
 
    return tmp

def max_node(root):
    tmp = root

    while(tmp.right != None):
        tmp = tmp.right
 
    return tmp
 
def delete(root, key):

	if root == None:
		return root

	if root.key > key:
		root.left = delete(root.left, key)

	elif root.key < key:
		root.right = delete(root.right, key)

	else:
		if root.left == None:

			tmp = root.right
			root = None
			return tmp

		elif root.right == None:

			tmp = root.left
			root = None
			return tmp

		else:
			tmp = min_node(root.right)
			root.key = tmp.key
			root.right = delete(root.right, tmp.key)
 
	return root

def get_inorder(root):

	array = []

	def inorder_walk(root):

		nonlocal array

		if root:
			inorder_walk(root.left)
			array.append(root.key)
			inorder_walk(root.right)

	inorder_walk(root)

	return array

def next_elem(root, key):

	array = get_inorder(root)

	if len(array) == 0:
 		return "none"

	for i in range(len(array)):

		if array[i] > key:
			return array[i]

	return "none"

def prev_elem(root, key):

	array = get_inorder(root)

	if len(array) == 0:
 		return "none"

	for i in range(len(array)):

		if array[i] >= key:
			if i != 0:
				return array[i - 1]

			return "none"

	return array[len(array) - 1]

	

root = None

inputf = list(open("bstsimple.in"))
outputf = open("bstsimple.out", "w")

for line in inputf:

	if "insert" in line:
		root = insert(root, int(line[7:]))
	elif "exists" in line:
		outputf.write(exists(root, int(line[7:])) + "\n")
	elif "delete" in line:
		root = delete(root, int(line[7:]))
	elif "next" in line:
		outputf.write(str(next_elem(root, int(line[5:]))) + "\n")
	elif "prev" in line:
		outputf.write(str(prev_elem(root, int(line[5:]))) + "\n")

outputf.close()