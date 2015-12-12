#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "utility.h"


int readArgs(int argc, char **argv, string &url, int &chunksnum, int &chunksize,
             int &downloadSize, int &parallel, string &filename)
{
  int c;
  
  const option long_options[] = { {"parallel", no_argument, 0, 0},
                                  {"chunk_num", required_argument, 0, 0},
                                  {"chunk_size", required_argument, 0, 0},
                                  {"download_size", required_argument, 0, 0},
                                  {0, 0, 0, 0}
  };

  while (true) {
    int option_index = 0;
    c = getopt_long(argc, argv, "o:", long_options, &option_index);
    if (c == -1)
      break;

    switch (c) {
      case 0:
        if (long_options[option_index].name == "parallel") {
          parallel = 1;
        }
        if  ( (long_options[option_index].name == "download_size") && (optarg) ) {
          downloadSize = atoi(optarg);
#ifdef DEBUG      
          printf("download_size = %d  %s \n ", downloadSize, optarg);
#endif    
        }

        if  ( (long_options[option_index].name == "chunk_size") && (optarg) ) {
          chunksize = atoi(optarg);
#ifdef DEBUG    
          printf("chunk_size = %d  %s \n ", chunksize, optarg);
#endif    
        }

        if  ( (long_options[option_index].name == "chunk_num") && (optarg) ) {
          chunksnum = atoi(optarg);
#ifdef DEBUG
          printf("chunk_num = %d  %s \n ", chunksnum, optarg);
#endif    
        }
        printf("\n");
        break;

      case 'o':
#ifdef DEBUG      
        printf("option c with value '%s'\n", optarg);
#endif  
        filename.assign( optarg );
        break;
    }
  }
  if (optind >= argc) {
    fprintf(stderr, "Usage: %s  [-o output_file] [--chunk_num cn] [--chunk_size cs] \
    [--download_size ds] URL \n", argv[0]);
    exit(EXIT_FAILURE);
  }
  else 
    url.assign( argv[optind] );
}

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) 
{
  string data((const char*) ptr, (size_t) size * nmemb);
  *((stringstream*) stream) << data << endl;
  return size * nmemb;
}

string NumberToString ( int Number )
{
  ostringstream ss;
  ss << Number;
  return ss.str();
}


