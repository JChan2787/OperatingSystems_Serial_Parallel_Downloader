//CPSC351 -- Project 1c Extra-Credit multi-search
//Group   -- Jose Chan Jr.
//	     892984154
//	     Brandon Dang
//	     894426345

//Pre-processor directives:
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

//The main will take in arguments 
int main(int argc, char* argv[])
{
	//Declaring local variables
	pid_t processID; //Contains the process ID 
	ifstream readFile; //Input file stream
	int counter; //Counter, will keep track of how to split the list
	int child_counter; //Child counter to keep track of # of child processes
	int exit_status; //Contains the integer value of the exit()
	vector<string> list; //Vector that will contain all the strings read by the input file stream
	bool isFound; //Will execute inside the child process, if the string in the sub-list is found
	bool found; //This will tell the program if the key is really found
	string tempVal; //Temporary variable to contain strings

	//Initializing local variables
	isFound = false;
	found = false;
	counter = 0;	
	child_counter = 0;	

	//Reading the file passed as an argument
	readFile.open(argv[1]);	
	
	//Reading he input file stream, will keep reading until readFile no longer reads any characters 
	//in the txt file
	while(readFile >> tempVal)
	{
		list.push_back(tempVal);
	}
	
	//Checks if the third argument entered by the user doesn't exceed the size of the vector 
	if((atoi)(argv[3]) <= list.size())
	{
		//Do while loop will keep running so long as the counter does not exceed the vector size
		do
		{
			processID = fork(); //fork a process
			++child_counter; //Increment the child counter

			//Fork has failed
			if(processID < 0)		
			{
				perror("Fork failed");
				exit(-1);
			}
		
			//Child process
			else if(processID == 0)		
			{
				//Declaring a local variable
				int i = counter; //This will be the sentinel value for our while loop
					         //and will contain the value of counter
			
				//The while loop will run and split the vector accordingly, as specified by the user.
				//As long as 'i' is less than the vector size divided by the number of child processes
				//the user specifies AND 'i' is less than the vector size, it will run.
				while((i < counter + list.size()/(atoi)(argv[3])) && i < list.size())
				{ 
					//Checks if current element of the vector is equal to the key
					if((string)(argv[2]) == list.at(i))
					{
						isFound = true; //Assign true to isFound
					}

					++i; //Increment i
				}
				
				//If is Found is true, then the exit value of this child is zero, otherwise it's 1
				if(isFound == true)
				{
					exit(0);
				}
				else
				{
					exit(1);
				}
			}

			//Re-initializing some variables
			isFound = false;
			counter += list.size()/(atoi)(argv[3]);
		}
		while(counter < list.size());

		//The parent will now execute wait() equal to the number of children made
		for(int i = 0; i < child_counter; i++)
		{		
			//If the exit status is < 0, error
			if(wait(&exit_status) < 0)
			{
				perror("wait");
				exit(-1);
			}
			
			//If child, assign true to 'found' and kill the process
			if(WEXITSTATUS(exit_status) == 0)
			{
				found = true;
				kill(processID, SIGKILL);
			}
		}
		
		//If the exit value for ALL the children is NOT zero, then the key was not found
		//Otherwise, it is found. 
		if(found == false)
		{
			cout << "Not found." << endl;
		}
		else
		{
			cout << "Found!" << endl;
		}
	}
	//Error message that will tell the user to enter the proper number of children to fork
	else
	{
		perror("ERROR -- List can't be split into that many elements!");
		exit(-1);
	}
	
	//Closing the input file stream
	readFile.close();

	return 0;
}
