# Dictionary-Using-Tries
# Problem Statement:
Through this project, we intend to help the user to store words and their meanings. It also allows for users to search for a specific word and fetch its meaning from the collection of previously stored data. Along with searching, this program also allows for the user to modify the meaning of a previously stored word, by searching for the word and storing the new meaning and also to delete a word and its meaning.
# Data structure used:
For the implementation of the dictionary, we used Trie. Trie is a special data structure that is used to store strings that can be visualized like a graph. It consists of nodes and edges. Each node consists at max 26 children and edges connect each parent node to its children. Dictionary can be implemented using other concepts like hash tables, but using a Trie allows for data to be searched faster. It also avoids the collisions that can occur if hash tables are used. Using Trie allows to skip the hassle of choosing an appropriate hash function. Trie has predetermined alphabetical ordering which makes it easier to use to implement a dictionary and find and store words with common prefix.
# Time complexity: 
We can search a key in O(M) time, where M is length of the string
# Space complexity: 
Memory requirements of Trie is O(ALPHABETSIZE * Key Length * N), where N is the number of keys in Trie.

