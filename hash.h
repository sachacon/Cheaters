// file includes declaration of hash function and objects 
#ifndef _HASH_H
#define _HASH_H

#include <string>
using namespace std;

int getdir (string dir, vector<string> &files);

class HashEntry{
    private:
	int value;
	HashEntry *next;
    public:
	HashEntry(int value){
	    this->value = value;
	    this->next = NULL;
	}
	int getValue(){	
	    return value;
	}
	void setValue(int value){
	    this->value = value;
	}
	HashEntry *getNext(){
	    return next;
	}
	void setNext(HashEntry *next){
	    this->next = next;
	}
};

class Hash {
    private:
    	int table_size;
	HashEntry **table;
	int collisions[1000][1000]; 

    public:
	// Constructor defines how large the hash table will be
	// parameter should be a very large prime number
  	Hash(int size); 			
       
  	// hashfunc() takes key, string of n words, and 
  	// returns the index to place in hash table	
	int hashfunc(string chunk);
	void put(int hash, int value);
	void printcollisions(int size, int min, vector<string>& files); 
	~Hash();		 	

};

#endif
