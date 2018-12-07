// this file includes the implementation of hash function 
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <cmath>
#include "stdlib.h"
#include "hash.h"

using namespace std;

int getdir (string dir, vector<string> &files){
    DIR *dp;
    struct dirent *dirp;
    if(( dp = opendir(dir.c_str())) == NULL){
	cout << "Error(" << errno << ") opening " << dir << endl;
  	return errno;
    }
    
    while ((dirp = readdir(dp)) != NULL){
	files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

Hash::Hash(int size){
    table_size = size;
    table = new HashEntry*[size];
    for (int i = 0; i < size; i++){
	table[i] = NULL;
    }
    
        
}

int Hash::hashfunc(string chunk){
    const int SIZE = 10009;
    long long unsigned hashval;
    int key = atoi(chunk.c_str());
    for(string::iterator it=chunk.begin(); it != chunk.end(); it++){       
 	 hashval = *it + 3 * hashval;
    }
    return hashval % SIZE;
}

// VALUE IS THE INDEX OF FILE FROM VECTOR OF FILES, KEY IS THE INDEX OF HASH TABLE

void Hash::put(int hash, int value){
    if (table[hash] == NULL){
	table[hash] = new HashEntry(value);
    }
    else{
	HashEntry *entry = table[hash];
	while(entry->getNext() != NULL){
	    // You've already hashed this sequence for this file
	    if(entry->getValue() == value){
		return;
	    }
	    collisions[hash][entry->getValue()] += 1;
	    entry = entry->getNext();
	}
	entry->setNext(new HashEntry(value));
    }
}

void Hash::printcollisions(int size, int min, vector<string>& files){
    for(int i = 0; i < size; i++){
	for(int j = 0; j < size; j++){
	    if ( i != j){
	        if (collisions[i][j] > min){
		    cout << collisions[i][j] << ": " << files[i] << ", " << files[j] << endl;
	        }
	    } 
	}
    }	
} 

Hash::~Hash(){
    for (int i = 0; i < table_size; i++){
	if(table[i] != NULL){
	    HashEntry *prevEntry = NULL;
	    HashEntry *entry = table[i];
	    while (entry != NULL){
		prevEntry = entry;
		entry = entry->getNext();
		delete prevEntry;
	    }
	}
    }
    delete[] table;    
}


