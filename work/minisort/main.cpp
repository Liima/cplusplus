#include "FileReader.h"
#include "MaxMinFinder.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main(int argc, char * argv[])
{
	vector<string> strings;
	vector<string> sortedStrings;
	try
	{
		FileReader in("strings.txt");
		while (!in.endOfFile())
		{
			std::string line = in.readLine();
			if (line.size() > 0)
			{
				strings.push_back(line);

			}
		}
	
		while(strings.size()>0)
		{
			MaxMinFinder<string> finder(*(strings.begin()));
			finder.test(strings);
			sortedStrings.push_back(finder.min());
			auto it = find(strings.begin(),strings.end(),finder.min());
			cout << *it << endl;
			strings.erase(it);
			
			
		}
	}
	catch (std::string err)
	{
		std::cout << "Error: " << err << std::endl;
	}


}