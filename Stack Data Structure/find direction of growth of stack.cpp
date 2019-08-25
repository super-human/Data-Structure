#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
/*
1) Make a local variable in main.
2) Write another function fun() with its own local variable.
3) Make a call to fun() from main. Compare addresses of two local variable. If address of fun()’s local variable is more than main’s local variable, then stack grows upward (i.e., addresses increase)
*/

void foo(int *local_in_main)
{
	int local_in_fun;
	if(&local_in_fun>local_in_main)
		std::cout<<"stack is growing upwards"<<'\n';
	else
		std::cout<<"stack is growing downwards"<<'\n';
}

int main(int argc, char const *argv[])
{
	int local_in_main;
	foo(&local_in_main);
	return 0;
}
