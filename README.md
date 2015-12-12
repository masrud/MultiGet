Run ./MultiGet without any argument to see the usage


Design decision:
To implement the solution, I used the libcurl library http://curl.haxx.se/libcurl/
The solution supports both synchronous download and parallel download. 
The parallel download is implemented using the multi interface of the libcurl library.
It allows the program to transfer multiple files (chunks of a file) at the same 
time without the need to use multiple threads.



