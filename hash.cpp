// this file includes the implementation of hash function 
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

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


void Hash::Hash(int n){
    this->size = n;
    // table = new ...     
}

void Hash::insertItem(int key){

}

void Hash::deleteItem(int key){

}




