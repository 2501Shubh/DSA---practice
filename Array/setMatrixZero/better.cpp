#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	/*
		-> we won't traverse the rows and columns for every 0, everytime 
		-> rather, we will keep two arrays: row[] and column[]
		-> it will keep a track if theres any 0 in a particular row/coumn
		-> which will be used later to set matrix 0
	*/

	int row[n] = {0};   //O(n)
	int column[m] = {0};    //O(m)

	//if a row/column has a 0, that entire row/coumn will be zero
	for(int i=0; i<n; i++)      //O(n*m)
	{
		for(int j=0; j<m; j++)
		{
			if(matrix[i][j] == 0)
			{
				row[i] = 1;
				column[j] = 1;
			}
		}
	}

	for(int i=0; i<n; i++)      //O(n*m)
	{
		for(int j=0; j<m; j++)
		{
			if(row[i] == 1 || column[j] == 1)
			{
				matrix[i][j] = 0;
			}
		}
	}
	return matrix;
}

/*
See, we know it will take n^2 time complexity for sure but in the optimal solution we can optimize the space complexity for sure!

    Time Complexity: O(n*m) + O(n*m) = 2 * O(n*m)
                   ~ n^2

    Space Complexity: O(n) + O(m)
*/
