#include <iostream>
#include <string>
#include <thread>

using std::cout;
using std::cin;
using std::endl;

void pause()
{
	char ch;
	std::string str = "PRess any key to continue...";
	cout << str;
	cin >> ch;
}

//thread 1
//runs a recursive fibonacci function and prints outputs
int fib(int start)
{
		if(start == 0 || start == 1)
		{
			return 1;
		}
		else
		{
			return fib(start - 1) + fib(start - 2);
		}
}

void fibWrapper(int totalRuns)
{
	int i = 0;
	while(i < totalRuns)
	{
		int n = fib(i);
		cout << "Fib(" << i << ") = " << n << endl;
		++i;
	}
}

//thread 2
//runs a recursive ackermann function and prints outputs

int main()
{
	int goal = 10;
	fibWrapper(goal);

	pause();

	return 0;
}