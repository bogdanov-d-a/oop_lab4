#include "stdafx.h"
#include "Utils.h"

bool AssignIfGreater(unsigned &target, unsigned source)
{
	if (source <= target)
	{
		return false;
	}

	target = source;
	return true;
}
