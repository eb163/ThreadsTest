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

void fibPrint(int i, int n)
{
	cout << "Fib(" << i << ") = " << n << endl;
}

void fibWrapper(int totalRuns)
{
	int i = 0;
	while(i < totalRuns)
	{
		int n = fib(i);
		fibPrint(i, n);
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

void ackPrint(int i, int j, int n)
{
	cout << "Ack(" << i << ", " << j << ") = " << n << endl;
}

void ackWrapper(int totalX, int totalY)
{
	int i = 0, j = 0;
	while (i <= totalX && j <= totalY)
	{
		int n = ack(i, j);
		ackPrint(i, j, n);
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
	int fibGoal = 25;
//	fibWrapper(fibGoal);

	int ackGoalX = 3, ackGoalY = 10;
//	ackWrapper(ackGoalX, ackGoalY);

	std::thread fibThread(fibWrapper, fibGoal);
	std::thread ackThread(ackWrapper, ackGoalX, ackGoalY);

	ackThread.join();
	fibThread.join();

	pause();

	return 0;
}