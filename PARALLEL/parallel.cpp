//CPSC351 -- Project 1b Parallel Downloader
//Group   -- Jose Chan Jr.
//	     892984154
//	     Brandon Dang
//	     894426345

//Pre-Processing Directives:
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main()
{
	//Declaring local variables
	pid_t processID; //Contains the process ID 
	ifstream readFile; //readFile will contain the input file stream
	int counter = 0; //Counter will keep track of many children were created
	string tempVal; //tempVal will store the strings by the input file stream
	vector<string> urlList; //Vector that will be containing strings, which will be URLs
		
	//Opening the input file stream
	readFile.open("urls.txt");
	
	//Reading he input file stream, will keep reading until readFile no longer reads any characters 
	//in the txt file
	while(readFile >> tempVal)
	{	
		counter++; //Increment counter
		processID = fork(); //Fork a process
		
		//If fork failed
		if(processID < 0)
		{
			perror("Fork failed");
			exit(-1);
		}
		//If its a child process
		if(processID == 0)
		{
			execlp("/usr/bin/wget", "wget", tempVal.c_str(), NULL);			
		}

	}	
	
	//Parent will not wait equal to the number of children were created	
	for(int i = 0; i < counter; i++)
	{		
		wait(NULL);
		cout << "Process: " << i << " terminated." << endl;	
	}

	//Closing the input file stream
	readFile.close();
			
	return 0;
}
