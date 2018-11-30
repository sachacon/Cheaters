#include <iostream>
#include <vector>

#include "hash.h"


int main (int argc, char *argv[]){


    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
   
    getdir(dir,files);
    for (unsigned int i = 0; i < files.size(); i++){
	cout << i << files[i] << endl;
    }  
  
    return 0;
}



