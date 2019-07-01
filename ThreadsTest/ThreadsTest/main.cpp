#include <iostream>
#include <string>
#include <thread>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void pause()
{
	char ch;
	std::string str = "Press any key to continue...";
	cout << str;
	cin >> ch;
}

void printFibResults(vector<int> results)
{
	for (int i = 0; i < results.size(); ++i)
	{
		cout << "Fib("<< i << ") = " << results.at(i) << endl;
	}
}

void printAckResults(vector<int> results, int endX, int endY)
{
	int x = 0, y = 0, i = 0;
	while (i < results.size())
	{
		cout << "Ack(" << x << ", " << y << ") = " << results.at(i) << endl;
		++y;
		if(y > endY)
		{
			++x; y = 0;
		}
		++i;
	}
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

void fibWrapper(int totalRuns, vector<int>& results)
{
	int i = 0;
	while(i < totalRuns)
	{
		int n = fib(i);
		results.push_back(n);
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

void ackWrapper(int totalX, int totalY, vector<int>& results)
{
	int i = 0, j = 0;
	while (i <= totalX && j <= totalY)
	{
		int n = ack(i, j);
		results.push_back(n);
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
	vector<int> fibResults;

	int ackGoalX = 3, ackGoalY = 10;
//	ackWrapper(ackGoalX, ackGoalY);
	vector<int> ackResults;

	cout << "Starting threads..." << endl;
	std::thread fibThread(fibWrapper, fibGoal, std::ref(fibResults));
	std::thread ackThread(ackWrapper, ackGoalX, ackGoalY, std::ref(ackResults));


	ackThread.join();
	fibThread.join();
	cout << "Threads are done running..." << endl;

	printFibResults(fibResults);
	printAckResults(ackResults, ackGoalX, ackGoalY);

	pause();

	return 0;
}