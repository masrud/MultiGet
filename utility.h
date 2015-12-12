#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


/*
This function processes the command line arguments. It takes as the input the 
argc and argv and extract the command line options from it.
*/
int readArgs(int argc, char **argv, string &url, int &chunksnum, int &chunksize,
             int &downloadSize, int &parallel, string &filename);

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

string NumberToString ( int Number );
