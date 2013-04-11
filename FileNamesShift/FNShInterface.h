#pragma once
#include <string>
class FNShInterface
{
public:
	FNShInterface(void);
	~FNShInterface(void);

	void ViewHelp(void);
	void DoShift(char*, char*, char*, char* = "0", char* = "999");
	std::string myitoa(int);
};

