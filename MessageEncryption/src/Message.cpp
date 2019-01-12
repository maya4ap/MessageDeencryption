/*
 * Message.cpp
 *
 *  Created on: May 23, 2017
 *      Author: Maya
 */

#include "Message.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>



using namespace std;

int main()

 {


	// create a message object with the content of Encrypted.txt
	Message m ;
		if (m.isEmpty())
			{
				std::cout << "Could not read message";
				return EXIT_FAILURE;
			}
		std::cout << "Original message: " << std::endl;
		m.dump();   std::cout << std::endl << std::endl;
		m.decode();
		m.fixCapitalization();
		std::cout << "Decoded message: " << std::endl;
		m.dump();
		std::cout << std::endl << std::endl;
		return EXIT_SUCCESS;
 }

Message::Message()
{

string filename;
	// TODO Auto-generated constructor stub
	fstream inputfile;

	inputfile.open("Encrypted.txt");

	if (!inputfile.good())
		{
			length=0;
		}
	else
		{

	    length = getFileSize(inputfile);
	    message = new char[length + 1];
	    for (int i = 0; i < length + 1; i++)
	        {
	            inputfile >>std:: noskipws;
	    		inputfile >> message[i];
	            //cout << message[i] << endl;
	        }
		}
	inputfile.close();
}

Message::~Message()
{

	 //TODO Auto-generated destructor stub
delete [] message;
}
void Message::decode()
{
	 for(int i=0;i<length;i++)//make everything lowercase to begin with
	 if(isupper(message[i-1]))
		   message[i]=tolower(message[i]);//toupper requires a variable to hold the change

	for(int i=0; i<length; i++)
	       switch(message[i])
	       {
	       case 'a':
		   	   message[i]=code[0];//if there is a letter a replace it with the first element of code array
		   	   break;
	       case 'b':
	    	   message[i]=code[1];
	    	   break;
	       case 'c':
	    	   message[i]=code[2];
	    	   break;
	       case 'd':
	    	   message[i]=code[3];
	    	   break;
	       case 'e':
	    	   message[i]=code[4];
	       	   break;
	       case 'f':
	    	   message[i]=code[5];
	       	   break;
	       case 'g':
	    	   message[i]=code[6];
	       	   break;
	       case 'h':
	    	   message[i]=code[7];
	    	   break;
	       case 'i':
	       	   message[i]=code[8];
	       	   break;
	       case 'j':
	       	   message[i]=code[9];
	       	   break;
	       case 'k':
	       	   message[i]=code[10];
	       	   break;
	       case 'l':
	       	   message[i]=code[11];
	       	   break;
	       case 'm':
		   	   message[i]=code[12];
		   	   break;
	       case 'n':
		   	   message[i]=code[13];
			   break;
	       case 'o':
	    	   message[i]=code[14];
	    	   break;
	       case 'p':
	    	   message[i]=code[15];
	    	   break;
	       case 'q':
	    	   message[i]=code[16];
	    	   break;
	       case 'r':
	    	   message[i]=code[17];
	    	   break;
	       case 's':
		   	   message[i]=code[18];
	       	   break;
	       case 't':
	    	   message[i]=code[19];
	    	   break;
	       case 'u':
	    	   message[i]=code[20];
	    	   break;
	       case 'v':
	    	   message[i]=code[21];
	    	   break;
	       case 'w':
	    	   message[i]=code[22];
	    	   break;
	       case 'x':
		   	   message[i]=code[23];
		   	   break;
	       case'y':
	    	   message[i]=code[24];
	    	   break;
	       case 'z':
	    	   message[i]=code[25];
	    	   break;
	       }

}


void Message::fixCapitalization()
{
	message[0]=toupper(message[0]);//captalizes first letter specifically because
	//my condition capitalizes letters followed by periods
   for(int i=0;i<length;i++)
   {
	   if(message[i] =='.')
	   {
		   //cout <<message[i];
	   message[i+2] = toupper(message[i+2]);
	   }
   }


}



void Message::dump() const//message getter function(message is private)
{
		for (int i=0;i<length; i++)
			cout << message[i];
}

bool Message::isEmpty() const
{
if (length == 0)
    {
        return true;
    }
else
	return false;

}
