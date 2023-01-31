#include <iostream>
using namespace std;

bool is_promosing(int i, int w[], const int n, int * include_w, const int t)
{
	bool check1;
	bool check2;
	int sum = 0;
	int sum2 = 0;
	for (int j = 1; j <= i; j++)
	{
		sum = sum + w[j] * include_w[j];
	}
	check1 = ((w[i+1] + sum) <= t);
	for (int j = i+1; j <= n; j++)
	{
		sum2 = sum2 + w[j];
	}
	check2 = ((sum + sum2) >= t);
	if (check1)
	{
		if (check2)
		{
			return true;
		}
	}
	else return false;
}

void find_subset_sum(int i, int w[], const int n, const int t, int include_w[], int  weight_so_far, int  weight_left, bool & check)
{
	if (!check)
	{
		if (is_promosing(i, w, n, include_w, t))
		{
			if (weight_so_far == t)
			{
				for (int k = 1; k <= i; k++)
				{
					cout << "X" << k << " = " << include_w[k];
					if (k + 1 != i + 1)
					{
						cout << " , ";
					}
				}
				check = true;
			}
			else
			{
				include_w[i + 1] = 1;
				find_subset_sum(i + 1, w, n, t, include_w, weight_so_far + w[i + 1], weight_left - w[i + 1], check);
				include_w[i + 1] = 0;
				find_subset_sum(i + 1, w, n, t, include_w, weight_so_far, weight_left, check);
			}
		}
	}
	else
	{
		return;
	}
}
	
int main()
{
	int w[5] = {0,3,4,5,6 }; 
	int t = 13;
	int n = 4;
	int include_w[5] = {0,0,0,0,0};
	int initial = 0;
	int sum = 0;
	bool check = false;
	for (int i = 1; i < 5; i++)
	{
		sum = sum + w[i];
	}
	cout << "Example one: \nArray: 3,4,5,6\nResult: ";
	find_subset_sum(0, w, n, t, include_w, initial, sum, check);
	cout << "\n___________________________________________________\n\n";
	int w2[8] = { 0,5,7,10,12,15,18,20 };
	t = 35;
	n = 7;
	int include_w2[8] = { 0,0,0,0,0,0,0,0};
	sum = 0;
	check = false;
	initial = 0;
	for (int i = 1; i < 8; i++)
	{
		sum = sum + w2[i];
	}
	cout << "Example two: \nArray: 5,7,10,12,15,18,20\nResult: ";
	find_subset_sum(0, w2, n, t, include_w2, initial, sum, check);
	cout << endl;

	system("pause");
	return 0;
}