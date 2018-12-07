#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <queue>
#include <sstream>
#include <fstream>
#include "hash.h"

using namespace std;

void strip_string(string& words);

// STRIP_STRING TAKES OUT CHARACTERS THAT AREN'T LETTERS, CHANGES CAPITALS TO LOWERCASE
void strip_string(string& words){
    string::iterator iter;
    int val;			// WILL HOLD ASCII VALUE OF CHARACTERS
    for(iter = words.begin(); iter != words.end(); iter++){
	val = int(*iter);
	if(val < 48 || val > 122 || (val > 57 && val < 65) || (val > 90 && val < 97)){
	    words.erase(iter);
	    iter--;
	}
	if(val > 65 && val < 91){
	    char c = val + 32;
	    *iter = c;    
	}  
    }	
}

int main (int argc, char *argv[]){

    // CHECK FOR CORRECT INPUT AMOUNT 
    if(argc != 3 && argc != 4){
	cout << "Incorrect amount of inputs for this program" << endl;
	return 1; 
    }
    
    // 	GET SEQUENCE LENGTH FROM INPUT 
    int n, j;
    if(argc == 3){
	stringstream input(argv[2]);
 	input >> n; 
    }
    else{
    	stringstream input(argv[2]);
 	input >> n;
    }
    cout << "input sequence length is " << n << endl;

   
    // GET STRING VECTOR OF FILENAMES 
    string dir = string("sm_doc_set");
    vector<string> files;
    getdir(dir,files);
    files.erase(files.begin(), files.begin()+2);

    // DECLARE HASH TABLE
    Hash h(500009);
    // cout << h.hashfunc("next") << endl << h.hashfunc("ontothenextone") << endl << h.hashfunc("ashevildead") << endl
    //	 << h.hashfunc("nextw") << endl;

    // READ FROM TEXT FILE, GET CHUNKS
    ifstream myFile;
    string sequence, word, path; 
    vector<string> words;
    int index;    
    for (unsigned int i = 0; i < files.size(); i++){
	path = "/home/ecelrc/students/schacon/Cheaters/sm_doc_set/" + files[i];
	myFile.open(path.c_str());
	while (myFile) {
	    if(words.empty()){
		for(j = 0 ; j < n; j++){
		    myFile >> word; 
		    words.push_back(word);
		    sequence += word;
		}
	    }
	    else{
		myFile >> word;
 		words.erase(words.begin());
		words.push_back(word);
		for(j = 0; j < n ; j++){
		    sequence += words[j];
		} 	        
	    }
	    strip_string(sequence);
	    index = h.hashfunc(sequence);
	    h.put(index, i);	        
	    sequence.clear();
 	}
	myFile.close();
	sequence.clear();
    }

    if(argc == 4){
        // CREATE MATRIX AND CHECK FOR COLLISIONS
        int min;
   	stringstream input(argv[3]);
	input >> min;
        h.printcollisions(files.size(), min, files); 
		
    }
  
    return 0;
}



