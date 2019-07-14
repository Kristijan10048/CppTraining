#include <iostream>

using namespace std;

// You have given an integer array which contains numbers from 1 to 100 but one
// number is missing, you need to write a Java program to find that missing number in an array.
// You cannot use any open source library or Java API method which solves this problem. One
// trick to solve this problem is to calculate sum of all numbers in the array and compare with
// expected sum, the difference would be the missing number


//calculate sum from 1 to n
int SumToN(int n)
{
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += i;
	}
	
	return sum;
}

//calculate the sum of the array
int SumOfArray(int arr[], int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++ )
	{
		sum += arr[i];
	}
	
	return sum;
}

int main()
{
	const int C_MAX_LEN = 10;
	int tmpArr[] = {1, 2 , 3, 4, 5, 6, 7, 8, 9};
	
	int tmpSum = SumToN(C_MAX_LEN);
	int arrSum = SumOfArray(tmpArr, 9);
	printf("The sum to n is %d, the sum of the array is %d\n", tmpSum, arrSum);
	printf("Missing number is %d", tmpSum - arrSum);
}