/*
  prog4.h
  Donald Johnson
  CSCI 501
  10-2-18
  
  Header file for prog4
*/
#ifndef __PROG4_H__
#define __PROG4_H__

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string iFile = "/home/cs501/progs/18f/p4/prog4-in.cc";
const string oFile = "prog4-out.cc";

void openfiles (ifstream& is, ofstream& os);
void process_data (ifstream& is, ofstream& os);
void close_files (ifstream& is, ofstream& os);

#endif
