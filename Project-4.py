import heapq
class freqNode:
	def __init__(self, char = None, freq = None):
		self.char = char
		self.freq = freq
		self.parent = None
		self.code = None
		self.left = None
		self.right = None
	def __lt__(self, other):
		return self.freq < other.freq

def frequencyMap(filename):
	letterMap = {}
	contentOfFile = open(filename)
	for line in contentOfFile:
		for letter in line:
			letterMap.setdefault(letter, 0)
			letterMap[letter] += 1
	letterMap['EOF'] = 1 
	contentOfFile.close()
	return letterMap
	
def encodingTree(letterMap):
	pq = []
	for char, freq in letterMap.items():
		heapq.heappush(pq, freqNode(char, freq))
	while len(pq) > 1:
		leftNode = heapq.heappop(pq)
		rightNode = heapq.heappop(pq)
		sumNode = leftNode.freq + rightNode.freq
		newHeadNode = freqNode(None, sumNode)
		newHeadNode.left = leftNode
		newHeadNode.left.parent = newHeadNode
		newHeadNode.right = rightNode
		newHeadNode.right.parent = newHeadNode
		heapq.heappush(pq, newHeadNode)
	treeHead = heapq.heappop(pq)
	return treeHead

def addingCode(currNode, map, isLeft = True):
	if currNode is None:
		return
	if currNode.parent is None:
		addingCode(currNode.left, map)
		addingCode(currNode.right, map, False)
	else:
		if currNode.parent.code is None:
			if isLeft:
				currNode.code = "0"
			else:
				currNode.code = "1"
		else:
			if isLeft:
				currNode.code = currNode.parent.code + "0" 
			else:
				currNode.code = currNode.parent.code + "1"
		if currNode.char is not None:
			map[currNode.char] = currNode.code
		addingCode(currNode.left, map)
		addingCode(currNode.right, map, False)

def encodingMap(treeHead):
	map = {}
	addingCode(treeHead, map)
	return map
def encodingText(encodeMap,filename):
	codeString = ""
	contentOfFile = open(filename)
	for line in contentOfFile:
		for letter in line:
			codeString += encodeMap[letter]
	codeString += encodeMap['EOF']
	contentOfFile.close()
	numOfPaddingZeros= 8 - (len(codeString) % 8)
	codeString += '0' * numOfPaddingZeros
	
	BinaryFile = open("encodedFile.bin", "wb")
	bytesCode = int(codeString, 2)

	BinaryFile.write(bytesCode.to_bytes(len(codeString) // 8, 'big'))
	BinaryFile.close()

def decodingText(filename, treeHead):
	encryptedFile = open(filename, "rb")
	byte = encryptedFile.read(1)
	codeString = ""
	while byte:
		codeString += f"{ord(byte):08b}"
		byte = encryptedFile.read(1)
	encryptedFile.close()

	currNode = treeHead
	currString = ""
	for currBit in codeString:
		currString += currBit
		if currBit == '1':
			currNode = currNode.right
		else:
			currNode = currNode.left
		if currNode.char is not None:
			if currNode.char == 'EOF':
				return
			print(currNode.char, end = '')
			currString = ""
			currNode = treeHead

def main():
	print("Enter file name to encode: ")
	filename = input()
	codedFilename = "encodedFile.bin"
	letterMap = frequencyMap(filename)
	treeHead = encodingTree(letterMap)
	encodeMap = encodingMap(treeHead) 
	encodingText(encodeMap, filename)
	decodingText(codedFilename, treeHead)
	#print("\n")

main()
