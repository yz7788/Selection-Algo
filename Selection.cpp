#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

int partition_(int* integers, int left, int right, int pivot)
{
	if (left == right) return integers[left];
	int key = integers[pivot];
	if (left != pivot)
	{
		int victim = integers[left];
		integers[left] = integers[pivot];
		integers[pivot] = victim;
	}
	int index1 = left + 1;
	int index2 = right;
	while (index1 < index2)
	{
		while (integers[index1] <= key && index1 <= right)
		{
			index1++;
		}
		while (integers[index2] >= key && index2 > left)
		{
			index2--;
		}
		if (index1 < index2)
		{
			int victim = integers[index1];
			integers[index1] = integers[index2];
			integers[index2] = victim;
		}
	}
	if (key > integers[index2])
	{
		integers[left] = integers[index2];
		integers[index2] = key;
	}
	return index2;
}

int Dselect(int integers[], int left, int right, int index)
{
	if (left == right) return integers[left];
	int n = right - left + 1;
	int group_num = n / 5;
	if (group_num == 0)
	{
		for (int i = left + 1; i <= right; i++)
		{
			for (int j = left; j < i; j++)
			{
				if (integers[i] < integers[j])
				{
					int victim = integers[i];
					for (int k = i; k > j; k--)
					{
						integers[k] = integers[k - 1];
					}
					integers[j] = victim;
				}
			}
		}
		return integers[index];
	}
	int* new_integers = (int*)malloc(sizeof(int) * group_num);
	for (int i = 0; i < group_num; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (integers[left + 5 * i + j] < integers[left + 5 * i + k])
				{
					int victim = integers[left + 5 * i + j];
					for (int u = (5 * i + j); u >= (5 * i + k + 1); u--)
					{
						integers[left + u] = integers[left + u - 1];
					}
					integers[left + 5 * i + k] = victim;
				}
			}
		}
		new_integers[i] = integers[left + 5 * i + 2];
	}
	int median_index = group_num / 2;
	int p = Dselect(new_integers, 0, group_num - 1, median_index);
	int pivot;
	for (int k = left; k <= right; k++)
	{
		if (integers[k] == p)
		{
			pivot = k;
			break;
		}
	}
	int j = partition_(integers, left, right, pivot);
	if (j == index)
		return p;
	if (j > index)
		return Dselect(integers, left, j - 1, index);
	else
		return Dselect(integers, j + 1, right, index);
}

int Rselect(int* integers, int left, int right, int i)
{
	if (left == right)
		return integers[left];
	int pivot = rand() % (right - left + 1) + left;
	int p = integers[pivot];
	int j = partition_(integers, left, right, pivot);
	if (j == i)
		return p;
	if (j > i)
		return Rselect(integers, left, j - 1, i);
	else
		return Rselect(integers, j + 1, right, i);
}


int main()
{
	//srand(time(0));
	int algorithm_type;
	cin >> algorithm_type;
	int n;
	cin >> n;
	int i;
	cin >> i;
	int* integers = new int[n];
	for (int k = 0; k < n; k++)
	{
		cin >> integers[k];
	}
	if (algorithm_type == 0)
	{
		int index = Rselect(integers, 0, n - 1, i);
		cout << "The order-" << i << " item is " << index;
	}
	else if (algorithm_type == 1)
	{
		int index = Dselect(integers, 0, n - 1, i);
		cout << "The order-" << i << " item is " << index;
	}
}
