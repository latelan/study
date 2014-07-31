/*************************************************************************
	> File Name: reverse.cpp
	> Author: latelan, coolboy1353@163.com
	> Created Time: 2014-07-31 14:58:56
 ************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int A[] = {1,2,3,4,5,6,7};
	reverse(A,A+7);

	for(int i = 0;i<7;i++)
	{
		cout << A[i] << " ";
	}
}
