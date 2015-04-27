#include "stdafx.h"
#include "Utils.h"

using namespace std;

bool AssignIfGreater(unsigned &target, unsigned source)
{
	if (source <= target)
	{
		return false;
	}

	target = source;
	return true;
}

char GetCharFromStream(istream &in)
{
	char c;
	if (!in.get(c))
	{
		throw runtime_error("Unexpected end of file");
	}
	return c;
}
