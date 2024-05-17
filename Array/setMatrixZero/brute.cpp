#include <bits/stdc++.h>

//set that entire row as -1
void setRow(int i, vector<vector<int>> &matrix, int m)
{
	for(int j=0; j<m; j++)
	{
		if(matrix[i][j] != 0)
		{
			matrix[i][j] = -1;
		}
	}
}

//set that entire column as -1
void setColumn(int j, vector<vector<int>> &matrix, int n)
{
	for(int i=0; i<n; i++)
	{
		if(matrix[i][j] != 0)
		{
			matrix[i][j] = -1;
		}
	}
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	/*
		n: number of rows
		m: number of columns
	*/

	//check the intial 0's
	for(int i=0; i<n; i++)      //O(n*m)
	{
		for(int j=0; j<m; j++)
		{
			if(matrix[i][j] == 0)
			{
				setRow(i, matrix, m);   //O(m): for a given row, traverse the column
				setColumn(j, matrix, n);    //O(n): for a given column, traverse the row
			}
		}
	}

	for(int i=0; i<n; i++)      //O(n*m)
	{
		for(int j=0; j<m; j++)
		{
			if(matrix[i][j] == -1)
			{
				matrix[i][j] = 0;
			}
		}
	}
	return matrix;
}

/*
    Time Complexity: O(n*m)*(O(n)+O(m)) + O(n*m)
                   ~ n^3
*/