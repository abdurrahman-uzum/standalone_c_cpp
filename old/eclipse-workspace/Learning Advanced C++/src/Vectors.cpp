#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	for ( std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++ )
	{
		std::cout << *it << std::endl;
	}

	std::vector < std::vector<int> > grid(3, std::vector<int>(4,0));

	grid[1].push_back(1);

	for ( int i=0; i < grid.size(); i++ )
	{
		for ( int j=0; j < grid[i].size(); j++ )
		{
			std::cout << grid[i][j] << std::flush;
		}

		std::cout << std::endl;
	}





	return 0;
}
