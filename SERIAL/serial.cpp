//CPSC351 -- Project 1a Serial Downloader
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
	string tempVal;
		
	//Opening the input file stream
	readFile.open("urls.txt");

	//Reading he input file stream, will keep reading until readFile no longer reads any characters 
	//in the txt file
	while(readFile >> tempVal)
	{
		//Fork a process
		processID = fork();
	
		//Fork has failed
		if(processID < 0)		
		{
			perror("Fork failed");
			exit(-1);
		}
		//Child process
		else if(processID == 0)		
		{
			//execlp instruction executed
			execlp("/usr/bin/wget", "wget", tempVal.c_str(), NULL);
		}
		//Parent process
		else
		{
			wait(NULL);
		}
	}	

	//Closing the input file stream
	readFile.close();
			
	return 0;
}
