#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	/*
		-> for 0's tracking of each row and column we have taken 0th row and 0th column into consideration
		-> for column tracking: matrix [0][m] -> 0th row
		-> for row tracking: matrix [n][0]  -> 0th column
	*/
	int col0 = 1;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(matrix[i][j] == 0)
			{
				//column-tracking: to eradicate common point problem
				if(j != 0)
				{
					matrix[0][j] = 0;
				}
				else
				{
					col0 = 0;
				}
				
				//row-tracking:
				matrix[i][0] = 0;
			}
		}
	}

	// to set all the elements of row and column which had 0 -> as 0
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<m; j++)
		{
			if(matrix[i][j] != 0)		//if 1, then check is its tracking row/column is 0?
			{
				if(matrix[0][j] == 0 || matrix[i][0] == 0)	//if yes
				{
					matrix[i][j] = 0;	//mark the element as 0
				}
			}
		}
	}

	//time for tracking matrix[0][0] spot:
	if(matrix[0][0] == 0)
	{
		for(int j=0; j<m; j++)
		{
			matrix[0][j] = 0;		
		}
	}

	if(col0 == 0)
	{
		for(int i=0; i<n; i++)
		{
			matrix[i][0] = 0;
		}
	}

	return matrix;
}

/*
    Time Complexity: 2 * O(n*m)
    Space Complexity: O(1) -> no extra space was taken(except one variable col0), calculated using 0th row and 0th column for tracking 0's.
*/