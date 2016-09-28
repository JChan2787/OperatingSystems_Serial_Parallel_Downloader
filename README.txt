Jay Chan Jr. - jchan81@csu.fullerton.edu - 892984154
Brandon Dang - alvisblu@csu.fullerton.edu - 894426345

Programming Language used: "C++"

Instructions to run the program:
	
	First you will have to be in terminal and change the directory to the directory that contains all the files.
	To run the serial downloader, you need to have a text file called "urls.txt", it has be called that
	otherwise it won't donwload the files. This will come with a make file, to use it, type in "make" in
	the terminal and it will start to compile the code. Now to run this, type "./serial.out", and the program
	will start downloading. To calculate the time for the serial downloader, type in "time ./serial" into the
	command line.

	To run the parallel downloader, you need to have the text file called "urls.txt". Type in "make" in the
	terminal. Next to run it, type "./parallel.out" and the program will start downloading. To calculate the
	time for the parallel downloader, type in "time ./parallel".

	For extra credit multi-linear search, to run this program, we need to have a text file of any name inside
	the directory. This comes with a make file as well. To run we use:
	./multi-search <FILE NAME> <KEY> <NUMBER OF PROCESSES> (i.e., ./multi-search str.txt hello 3). If the
	result is found then it will say that the KEY was found.

Execution time for both downloaders 
	Since we were using the titan server to download two iso files
	which were too large to download in reasonable amount of time, we 
	instead used the two following links to test out the serial 
	and parallel downloader.
	
	URLs : http://i.imgur.com/okYm3jn.jpg (85 kb)
	       http://i.imgur.com/0rBUTT7.jpg (794 kb)
	Serial Time : real 0m2.579s ; 0m0.008s user ;sys 0m0.072s
	Parallel Time : real 0m1.020s ; 0m0.000s user ;sys 0m0.036s

Yes we did implement the extra credit.

When performing the downloaders for parallel, the command line consistently flickers between the multiple
donwloading bars, this is because the downloads are constantly updating the progress bar when there is
only one line for the command bar.