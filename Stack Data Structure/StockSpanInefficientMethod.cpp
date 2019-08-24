#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>


int main(int argc, char const *argv[])
{
	int n,j;
	std::cin>>n;
	int array[n];
	int stockArray[n];
	for (int i = 0; i < n; ++i)
		std::cin>>array[i];
	for (int i = 0; i < n; ++i)
	{
		j = 1;
		while(j<=i && array[i]>array[i-j])
			j++;
		stockArray[i]=j;
	}
	for (int i = 0; i < n; ++i)
		std::cout<<stockArray[i]<<" ";
	std::cout<<'\n';
	return 0;
}
