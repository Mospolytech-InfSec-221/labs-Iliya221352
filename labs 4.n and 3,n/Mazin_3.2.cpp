`#include <iostream>

void input(int*& arr,int& len) 
{
	std::cout << "input massive len:";
	std::cin >> len;
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		std::cin >> arr[i];
	}
}

void output(int* arr, int len)
{
	if (arr != nullptr)
	{
		for (int i = 0; i < len; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}
	else
	{
		std::cout << "array is empty\n\n";
	}
}

int num_len(int num, int count)
{
	int n = 10;
	while (num >= n)
	{
		count++;
		n *= 10;
	}
	return(count);
}

int sum_digit(int num)
{
	int count = 0, sum = 0,n=10;
	count=num_len(num, count);
	if (count % 2 == 0)
	{
		num /= 10;
	}
	for (int i = 0; i < count; i++)
	{
		sum += num % 10;
		num /= 100;
	}
	return(sum);
}

void sort(int* arr,int len)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (sum_digit(arr[j]) > sum_digit(arr[j + 1]))
			{
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
		}
	}
}

void sort_2(int* arr, int len)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j]%10 > arr[j + 1]%10)
			{
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
			else if (arr[j] % 10 == arr[j + 1] % 10)
			{
				if (arr[j] < arr[j + 1])
				{
					k = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = k;
				}
			}
		}
	}
}

int main()
{
	int choise = 0;
	int* arr = nullptr;
	int len = 0;
	while (choise != 5)
	{
		std::cout << "\n1. \n2. \n3. \n4.\n5.Exit \n\n";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
		{
			input(arr, len);
			break;
		}
		case 2:
		{
			output(arr, len);
			break;
		}
		case 3:
		{
			sort(arr, len);
			break;
		}
		case 4:
			sort_2(arr, len);
			break;
		}
	}
	delete[] arr;
}