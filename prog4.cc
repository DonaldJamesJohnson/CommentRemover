/*
  prog4.cc
  Donald Johnson
  CSCI 501
  Implementation file for prog4.h
  prog4.cc reads input from a file, clears any comments from that file, and outputs to a new file without comments.
*/
#include "prog4.h"

int main(){       //declares input and output file streams and calls the openfiles function
    ifstream infile;
    ofstream outfile;
    openfiles (infile, outfile);
    
    return 0;
}

void openfiles (ifstream& is, ofstream& os){   //if possible, opens the input and output files and calls the process_data function, after which the close_files function is called
    is.open(iFile.c_str());
    if (!is){
        cout << "Error could not open file: " << iFile;
        exit (EXIT_FAILURE);
    }
    os.open(oFile.c_str());
    if (!os){
        cout << "Error could not open file: " << oFile;
        exit (EXIT_FAILURE);
    }
    process_data(is, os);  
    close_files(is, os);
}

void process_data (ifstream& is, ofstream& os){  //the process_data function reads characters from the input file into a vector of characters, clears that vector of comments, and then writes the vector to the output file
    vector <char> c;
    char readc;
    int ilcounter = 0;
    int mlcounter = 0;
    int qcounter = 0;
    int loopcount = 0;
    while (is.good()){
         readc = is.get();
         c.push_back(readc);
    }
    for (unsigned i=0; i<c.size()-1; i++){
        if (c.at(i) == '\"' && qcounter == 0){
            if (ilcounter == 0 && mlcounter == 0){
                qcounter++;
            }
        }
        else if (c.at(i) == '\"' && qcounter > 0){
            if (ilcounter == 0 && mlcounter == 0){
                qcounter = 0;
            }
        }
        else if ((c.at(i) == '/' && c.at(i+1) == '/') && mlcounter == 0){
            if (qcounter == 0){
                ilcounter++;
            }
        }
        else if (c.at(i) == '\n' || c.at(i) == '\r'){
            ilcounter = 0;
        }
        else if ((c.at(i) == '/' && c.at(i+1) == '*') && ilcounter == 0){
            if (qcounter == 0){
                mlcounter++;
            }

        }
        else if (loopcount > 0 && qcounter == 0){
            if (c.at(i) == '/' && c.at(i-1) == '*'){
                mlcounter = 0;
                c.at(i) = '\0';
            }
        }
        if (mlcounter == 0 && ilcounter == 0){
            cout << c.at(i);
            os << c.at(i);
        }
        loopcount++;
    }   
}

void close_files (ifstream& is, ofstream& os){ //closes the input and output files
     is.close();
     os.close();
}

