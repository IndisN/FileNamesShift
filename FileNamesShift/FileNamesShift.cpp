// FileNamesShift.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "FNShInterface.h"

int main(int argc, char** argv)
{
	//FNShInterface fnsh;
	FNShInterface fnsh;
	
	switch (argc)
	{
//	case 1: fnsh.ViewHelp(); break;
	case 4: fnsh.DoShift(argv[1],argv[2],argv[3]); break;
	case 5: fnsh.DoShift(argv[1],argv[2],argv[3],argv[4]); break;
	case 6: fnsh.DoShift(argv[1],argv[2],argv[3],argv[4],argv[5]); break;
	default: fnsh.ViewHelp();
	}
	
	return 0;
}