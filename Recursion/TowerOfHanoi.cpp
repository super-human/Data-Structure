#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>

// Recursion Tower of Hanoi

void toh(int no_disk, char from, char middle, char to)
{
	if(no_disk == 1)
	{
		std::cout<<"Move disk from "<<from<<" to "<<to<<std::endl;
		return;
	}
	toh(no_disk-1,from,to,middle);
	std::cout<<"Move disk from "<<from<<" to "<<to<<'\n';
	toh(no_disk-1,middle,from,to);
}

int main(int argc, char const *argv[])
{
	toh(3,'A','B','C');
	return 0;
}
