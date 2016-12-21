#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
const int MaxVal = 9999;
const int MaxLen = 201;
struct tagPoint
{
	double x, y;
};
double distance(tagPoint *point, int i, int j)
{
	double distance = sqrt((point[i].x - point[j].x)*(point[i].x - point[j].x) + (point[i].y - point[j].y)*(point[i].y - point[j].y));
	return distance;
}
double dp(tagPoint *point, int n)
{
	vector<vector<double> >b(n + 1, vector<double>(n + 1));
	b[1][2] = distance(point, 1, 2);
	for (int j = 3; j <= n; j++)
	{
		for (int i = 1; i <= j-2; i++)
		{
			b[i][j] = b[i][j - 1] + distance(point, j - 1, j);
			double tmp = b[i][j];
		}
		b[j - 1][j] = MaxVal;
		for (int k = 1; k <= j - 2; k++)
		{
			double temp = b[k][j - 1] + distance(point, j, k);
			if (temp < b[j - 1][j])
			{
				b[j - 1][j] = temp;
			}
		}
	}
	b[n][n] = b[n - 1][n] + distance(point, n-1, n);
	return (b[n][n]);
}
int main()
{
	int num;
	cin >> num;
	tagPoint *point = new tagPoint[num + 1];
	for (int i = 1; i <=num; i++)
	{
		cin >> point[i].x >> point[i].y;
	}
	double minDis = dp(point, num);
	cout.setf(ios::fixed);
	cout << setprecision(2) << minDis << endl;
}