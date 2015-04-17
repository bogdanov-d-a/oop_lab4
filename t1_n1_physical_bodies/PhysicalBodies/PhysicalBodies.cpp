// PhysicalBodies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bodies.h"

using namespace std;

typedef function<void(string const& params)> Handler;
typedef map<string, Handler> StringToHandlerMap;

void PromptBodies(istream &strm, StringToHandlerMap const& handlers)
{
	string bodyType;
	while (strm >> bodyType)
	{
		auto it = handlers.find(bodyType);

		string params;
		getline(strm, params);

		if (it != handlers.cend())
		{
			if (!params.empty())
			{
				params = params.substr(1);
			}

			try
			{
				it->second(params);
			}
			catch (invalid_argument const& e)
			{
				cout << e.what() << "\n";
			}
		}
		else
		{
			cout << "Unknown body type: " << bodyType << "\n";
		}
	}
}

vector<string> SplitString(string const& str, char delimiter)
{
	vector<string> result;
	size_t startIndex = 0;

	while (startIndex < str.length())
	{
		const size_t delimiterIndex = str.find(delimiter, startIndex);
		const bool delimiterFound = (delimiterIndex != string::npos);
		const size_t partLength = delimiterFound ? delimiterIndex - startIndex : string::npos;

		result.push_back(str.substr(startIndex, partLength));
		startIndex = delimiterFound ? delimiterIndex + 1 : string::npos;
	}

	return result;
}

vector<int> StrVectorToIntVector(vector<string> strVector)
{
	vector<int> result(strVector.size());

	transform(strVector.cbegin(), strVector.cend(),
		result.begin(), [](string const& str){ return stoi(str); });

	return result;
}

void PrintWrongFormatMessage()
{
	cout << "Wrong format\n";
}

bool HandleArguments(string const& params, int paramCount, vector<int> &paramVector)
{
	try
	{
		paramVector = StrVectorToIntVector(SplitString(params, ','));
	}
	catch (invalid_argument const& e)
	{
		(void)e;
		PrintWrongFormatMessage();
		return false;
	}

	if (paramVector.size() != paramCount)
	{
		PrintWrongFormatMessage();
		return false;
	}

	return true;
}

double GetUnderwaterWeightCoefficient(CBody const& body)
{
	return ((body.GetDensity() - 1000) * body.GetVolume());
}

vector<shared_ptr<CBody>> PromptBodies(istream &strm)
{
	vector<shared_ptr<CBody>> bodies;
	StringToHandlerMap handlers;

	handlers["Compound"] = [&bodies](string const& params)
	{
		try
		{
			const vector<int> paramVector = StrVectorToIntVector(SplitString(params, ','));
			CCompound *newBody = new CCompound();

			for (int param : paramVector)
			{
				if (param >= 0 && static_cast<size_t>(param) < bodies.size())
				{
					newBody->AddBody(bodies[param]);
				}
			}

			bodies.push_back(shared_ptr<CBody>(newBody));
		}
		catch (invalid_argument const& e)
		{
			(void)e;
			PrintWrongFormatMessage();
		}
	};

	handlers["Cone"] = [&bodies](string const& params)
	{
		vector<int> paramVector;
		if (HandleArguments(params, 3, paramVector))
		{
			bodies.push_back(shared_ptr<CBody>(new CCone(paramVector[0], paramVector[1], paramVector[2])));
		}
	};

	handlers["Cylinder"] = [&bodies](string const& params)
	{
		vector<int> paramVector;
		if (HandleArguments(params, 3, paramVector))
		{
			bodies.push_back(shared_ptr<CBody>(new CCylinder(paramVector[0], paramVector[1], paramVector[2])));
		}
	};

	handlers["Parallelepiped"] = [&bodies](string const& params)
	{
		vector<int> paramVector;
		if (HandleArguments(params, 4, paramVector))
		{
			bodies.push_back(shared_ptr<CBody>(new CParallelepiped(paramVector[0], paramVector[1], paramVector[2], paramVector[3])));
		}
	};

	handlers["Sphere"] = [&bodies](string const& params)
	{
		vector<int> paramVector;
		if (HandleArguments(params, 2, paramVector))
		{
			bodies.push_back(shared_ptr<CBody>(new CSphere(paramVector[0], paramVector[1])));
		}
	};

	PromptBodies(cin, handlers);
	return bodies;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const vector<shared_ptr<CBody>> bodies = PromptBodies(cin);

	if (!bodies.empty())
	{
		auto maxMassElem = *max_element(bodies.cbegin(), bodies.cend(),
			[](shared_ptr<CBody> const& a, shared_ptr<CBody> const& b)
		{
			return (a->GetMass() < b->GetMass());
		});
		cout << "Body with maximal mass\n" << maxMassElem->ToString() << "\n";

		auto minWeightUnderwaterElem = *min_element(bodies.cbegin(), bodies.cend(),
			[](shared_ptr<CBody> const& a, shared_ptr<CBody> const& b)
		{
			return (GetUnderwaterWeightCoefficient(*a) < GetUnderwaterWeightCoefficient(*b));
		});
		cout << "Body with minimal underwater weight\n" << minWeightUnderwaterElem->ToString() << "\n";
	}
	else
	{
		cout << "Can't get results with no bodies\n";
	}

	return 0;
}
