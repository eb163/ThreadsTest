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
int ack(int a, int b)
{
	if(a == 0)
	{
		return b + 1;
	}
	else if (a > 0 && b == 0)
	{
		return ack(a - 1, 1);
	}
	else if ( a > 0 && b > 0)
	{
		return ack(a - 1, ack(a, b - 1));
	}
	else
	{
		return -1;
	}
}

void ackWrapper(int totalX, int totalY)
{
	int i = 0, j = 0;
	while (i <= totalX && j <= totalY)
	{
		int n = ack(i, j);
		cout << "Ack(" << i << ", " << j << ") = " << n << endl;
		++j;
		if (j % totalY == 0)
		{
			++i;
			j = j% totalY;
		}
	}
}

int main()
{
	int fibGoal = 10;
	fibWrapper(fibGoal);

	int ackGoalX = 3, ackGoalY = 8;
	ackWrapper(ackGoalX, ackGoalY);

	pause();

	return 0;
}