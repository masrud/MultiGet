Design decision:
To implement the solution to multi GET, I used the libcurl library: http://curl.haxx.se/libcurl/
The solution supports both synchronous download and parallel download. The parallel download is 
implemented using the multi interface of the libcurl library. It allows the program to transfer
multiple files (chunks of a file) at the same time without the need to use multiple threads.


Usage: ./MultiGet [-o outputfile] [--chunk_num chn] [--chunk_size chs] [--download_size ds] URL 

Run ./MultiGet without any argument to see the usage.

MultiGet can adjust the chunksize if the download size is different from 4MB. If the number of 
chunks is provided by the user, MultiGet uses it to determine the chunk size; otherwise, it uses 
the default number of chunks (i.e. four).


