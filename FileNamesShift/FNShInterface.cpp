#include "stdafx.h"
#include "FNShInterface.h"
#include <iostream>
#include <string>
#include "windows.h"
#include <stdlib.h>
#include <cmath>

FNShInterface::FNShInterface(void)
{
}


FNShInterface::~FNShInterface(void)
{
}

void FNShInterface::ViewHelp()
{
	std::cout << "\nHELP:\n" << "\tArguments: \n\n\t\tPath to the directory(obligatory - type anything) \n\t\tMask of the filename(obligatory) \n\t\tShift \n\t\tFirst file number \n\t\tLast file number\n\n";
	std::cout << "i.e. 'C:/dir/' img%.jpg 0 11\n\n";
}

void FNShInterface::DoShift(char * dir, char * mask, char* c_shift, char* c_first, char* c_last)
{
	std::string str_mask(mask);
	int digits = str_mask.find('%');
	int shift = atoi(c_shift);
	int first = atoi(c_first);
	int last = atoi(c_last);
	
	std::string partOne = str_mask.substr(0,digits);
	std::string partTwo = str_mask.substr(str_mask.find_last_of('%')+1);

	int success = 0;
	std::string prefix_o = "";
	std::string prefix_n = "";
	int len = std::string(c_first).length();

	if (shift > 0)
	{
		for (int i = last; i >= first; i--)
		{
			prefix_n = "";
			prefix_o = "";
			int lg = floor(log10(i+shift));
			if (len - lg - 1 > 0)
				prefix_n.append(len - lg - 1, '0');
			
			lg = floor(log10(i));
			if (len - lg - 1 > 0)
				prefix_o.append(len - lg - 1, '0');
			
			std::string oldFileName = /*dir + /*std::string("/") +*/ partOne + prefix_o + myitoa(i) + partTwo;
			std::string newFileName = /*dir + /*std::string("/") +*/ partOne + prefix_n + myitoa(i+shift) + partTwo;
			int r = rename(oldFileName.c_str(), newFileName.c_str());
			if (r == 0)
				++success;
			else
				perror(oldFileName.c_str());
		}
	}
	else 
	{
		for (int i = first; i <= last; i++)
		{
			prefix_n = "";
			prefix_o = "";
			int lg = floor(log10(i+shift));
			if (len - lg - 1 > 0)
				prefix_n.append(len - lg - 1, '0');
			
			lg = floor(log10(i));
			if (len - lg - 1 > 0)
				prefix_o.append(len - lg - 1, '0');

			std::string oldFileName = /*dir + /*std::string("/") +*/ partOne + prefix_o + myitoa(i) + partTwo;
			std::string newFileName = /*dir + /*std::string("/") +*/ partOne + prefix_n + myitoa(i+shift) + partTwo;
			int r = rename(oldFileName.c_str(), newFileName.c_str());
			if (r == 0)
				++success;
			else perror(oldFileName.c_str());
		}
	}

	std::cout << success << " files renamed successfully\n";
}

std::string FNShInterface::myitoa(int n)
{
	char buf[] = {"000"};
	_itoa_s(n,buf,10);
	return std::string(buf);
}