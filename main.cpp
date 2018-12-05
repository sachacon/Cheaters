#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "hash.h"

using namespace std;

int main (int argc, char *argv[]){

    // Check for 3 or 4 inputs 
    if(argc != 3 && argc != 4){
	cout << "Incorrect amount of inputs for this program" << endl;
	return 1; 
    }

    // get length of sequence from input 
    int n;
    if(argc == 3){
	stringstream input(argv[2]);
 	input >> n; 
    }
    else{
    	stringstream input(argv[3]);
 	input >> n;
    }
    cout << "input sequence length is " << n << endl;

    string dir = string("sm_doc_set");
    vector<string> files = vector<string>();
   
    getdir(dir,files);
    for (unsigned int i = 0; i < files.size(); i++){
	cout << i << files[i] << endl;
    }  
  
    return 0;
}



