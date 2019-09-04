public class NumMatrix {

	int[][] sumMatrix;

	public NumMatrix(int[][] matrix) {
		try {
			int rows = matrix.length;
			int cols = matrix[0].length;
			if (rows == 0 || cols == 0) return;
			sumMatrix = new int[rows + 1][cols + 1];
			for (int i = 1; i <= rows; i++)
				for (int j = 1; j <= cols; j++)
					sumMatrix[i][j] = sumMatrix[i - 1][j] + sumMatrix[i][j - 1] - sumMatrix[i - 1][j - 1] +
							matrix[i - 1][j - 1];
		} catch (ArrayIndexOutOfBoundsException e) {

		}
	}

	public int sumRegion(int row1, int col1, int row2, int col2) {
		if (sumMatrix == null) return 0;
		row2++;
		col2++;
		return sumMatrix[row2][col2] - sumMatrix[row1][col2] - sumMatrix[row2][col1] + sumMatrix[row1][col1];
	}
}
