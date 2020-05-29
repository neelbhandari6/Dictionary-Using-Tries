//
//  main.c
//  Dictionary
//
//  Created by Neel  Bhandari on 29/05/20.
//  Copyright © 2020 Neel  Bhandari. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
// trie node
struct TrieNode
{ struct TrieNode *children[ALPHABET_SIZE]; char value[30];// The meaning of the word // isEndOfWord is true if the node represents /* end of a word*/
    bool isEndOfWord;
    
};
    // Returns new trie node (initialized to NULLs)
    struct TrieNode *getNode(void) { struct TrieNode *pNode = NULL;  pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));  if (pNode) { int i;  pNode->isEndOfWord = false;  for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL; } return pNode; } // If not present, inserts key into trie // If the key is prefix of trie node, just marks leaf node 
    void insert(struct TrieNode *root, const char *key, char value[30]) {
     int level; int length = strlen(key); int index;  struct TrieNode *pCrawl = root;  for (level = 0; level < length; level++) { index = CHAR_TO_INDEX(key[level]); if (!pCrawl->children[index]) pCrawl->children[index] = getNode();  pCrawl = pCrawl->children[index]; } 
        
        // mark last node as leaf 
        strcpy (pCrawl->value, value); 
        pCrawl->isEndOfWord = true; 
        
    }  // Returns true if key presents in trie, else false 
bool search(struct TrieNode *root, const char *key)
{ int level; int length = strlen(key); int index; struct TrieNode *pCrawl = root;  for (level = 0; level < length; level++) { index = CHAR_TO_INDEX(key[level]);  if (!pCrawl->children[index]) return false;  pCrawl = pCrawl->children[index]; } if (pCrawl != NULL && pCrawl->isEndOfWord) { printf ("Word Found in the Dictionary. Meaning : %s\n!", pCrawl->value); } return (pCrawl != NULL && pCrawl->isEndOfWord);
        
}

struct TrieNode *searchAndReturn(struct TrieNode *root, const char *key)
 { int level; int length = strlen(key); int index; struct TrieNode *pCrawl = root;  for (level = 0; level < length; level++) { index = CHAR_TO_INDEX(key[level]);  if (!pCrawl->children[index]) return false;  pCrawl = pCrawl->children[index]; } if (pCrawl != NULL && pCrawl->isEndOfWord) { printf ("Key Found in the Dictionary %s ---- %s\n!", key, pCrawl->value); return pCrawl; } return NULL;
     
 }  void modify(struct TrieNode *root, const char *key) {  struct TrieNode *pCrawl = searchAndReturn(root, key); char ca; if (pCrawl) { printf("Element Found\n"); printf ("Word Found in the Dictionary %s ---- %s!\n", key, pCrawl->value); char value[30]; printf("Enter the new meaning: \n"); scanf("%c",&ca); fflush(stdin); scanf ("%[^\n]", value); for (int i = 0; i<strlen(pCrawl->value);i++) { pCrawl->value[i] = '\0'; } strcpy (pCrawl->value, value); printf("Word (%s) succesfully updated with the meaning: %s\n", key, pCrawl->value); } else { printf("Word not found\n"); } }  void deleteNode (struct TrieNode *root, const char *key) { struct TrieNode *pCrawl = searchAndReturn(root, key); printf ("Key Found in the Dictionary %s ---- %s\n!", key, pCrawl->value); if (pCrawl) { printf ("Word Found in the Dictionary and it will be deleted: %s ---- %s!\n", key, pCrawl->value); pCrawl->isEndOfWord = false; for (int i = 0; i < ALPHABET_SIZE; i++) pCrawl->children[i] = NULL; free (pCrawl); printf("Node deleted succesfully\n"); } } 

 int main() { struct TrieNode *root = getNode(); int i; char ca, key[20], value[30]; for (i = 0; i < ARRAY_SIZE(key); i++) insert(root, keys[i]); int ch; while (1) { printf("1. Insert word and meaning\n2. Search meaning\n3. Modify meaning\n4. Delete word(node)\n5. Exit\nEnter choice: \n"); scanf("%d", &ch);  if (ch == 1) {  printf ("Enter the word : "); scanf ("%s", key); printf ("Enter the meaning: "); scanf("%c",&ca); fflush(stdin); scanf("%[^\n]",value); insert (root, key, value); printf ("Insert Successful\n"); }  if (ch == 2) { char key[20]; printf ("Enter the word to search: "); scanf ("%s", key); bool isPresent = search (root, key); if (isPresent) { printf ("%s is present!\n", key); } else { printf ("Oops, cant find %s, Try again!\n", key); } }  if (ch == 3) { char key[20]; printf ("Enter the key to modify: "); scanf ("%s", key); modify(root, key); }  if (ch == 4) { char key[20]; printf ("Enter the key to delete: "); scanf ("%s", key); deleteNode(root, key); }  if (ch == 5) { break; } } return 0; }
