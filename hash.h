// file includes declaration of hash function and objects 
#ifndef _HASH_H
#define _HASH_H

#include <string>
using namespace std;

int getdir(string dir, vector<string> &files);

class Hash {
    private:
    	int size;
    	HashNode *table;

 	struct HashNode
	{
	    int value;
	    HashNode *next;
	};
	
	HashNode *head;
   
    public:
  	Hash(int sze); 				// Constructor	
  	void insertItem(int n);                 // inserts a key into the hash table
	void deleteItem(int key);		// deletes a key from the hash table
	int hashfunc(int n);			// map key to value 	

}:

#endif
