# Dictionary-Using-Tries
# Problem Statement:
Through this project, we intend to help the user to store words and their meanings. It also allows for users to search for a specific word and fetch its meaning from the collection of previously stored data. Along with searching, this program also allows for the user to modify the meaning of a previously stored word, by searching for the word and storing the new meaning and also to delete a word and its meaning.
# Data structure used:
For the implementation of the dictionary, we used Trie. Trie is a special data structure that is used to store strings that can be visualized like a graph. It consists of nodes and edges. Each node consists at max 26 children and edges connect each parent node to its children. Dictionary can be implemented using other concepts like hash tables, but using a Trie allows for data to be searched faster. It also avoids the collisions that can occur if hash tables are used. Using Trie allows to skip the hassle of choosing an appropriate hash function. Trie has predetermined alphabetical ordering which makes it easier to use to implement a dictionary and find and store words with common prefix.
# Time complexity: 
We can search a key in O(M) time, where M is length of the string
# Space complexity: 
Memory requirements of Trie is O(ALPHABETSIZE * Key Length * N), where N is the number of keys in Trie.
# Algorithm:
getNode():
Description: This function returns a new Trie node
Method: Allocates space to temporary variable pNode and sets all its alphabet nodes to NULL and
returns pNode.
insert(root, key, value):
Description: This function inserts a word in Trie
Method: Every character of the input key is inserted as an individual Trie node. Children is an array of pointers to the next level trie nodes. The key character acts as an index into the array children. If the input key is new or an extension of the existing key, then non-existing nodes of the tree are constructed and used to mark end of the word for the last node. If the input key is a prefix of an existing key in Trie, the last node of the key is marked as the end of word.
search(root, key):
Description: This function searches for a key(word) in Trie
Method: Searching for a word is similar to insert operation, except here, we only compare the characters and move down. The search can terminate due to end of the string or lack of key in the trie. This function returns true if the word exists and false if it doesn’t exist.
searchAndReturn(root, key):
Description: This function returns the node with the desired word to the function that evokes this function.
Method: This function works in the same way as search function does to locate the word and then returns the node to the function for which the required operation of either modifying the meaning or deleting the word along with the meaning is performed.
modify(root, key):
Description: This function is used to modify the meaning of an existing key in the Trie
Method: This function evokes searchAndReturn function to see if the word entered by the user whose meaning has to be modified exists or not. If the word exists, then the new meaning is asked for by the user, which replaces the old meaning of the word. If the word doesn’t exist, then an appropriate message is displayed.
deleteNode(root, key):
Description: This function is used to delete a word and it’s meaning from the Trie
Method: This function also evokes searchAndReturn function to see if the word entered by the user which has to be deleted exists or not. If the word exists, then the word and its meaning are deleted from the Trie. If the word doesn’t exist, then an appropriate message is displayed.
