#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
    int col0 = 1;
    // row -> matrix[..][0]
    // col -> matrix[0][..]
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if(j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] != 0) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if(matrix[0][0] == 0) {
        for(int j = 0; j < m; j++) matrix[0][j] = 0;
    }
    if(col0 == 0) {
        for(int i = 0; i < n; i++) matrix[i][0] = 0;
    }
    return matrix;
}

void printMat(vector<vector<int>> &matrix, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int> (m,0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int temp; cin >> temp;
            matrix[i][j] = temp;
        }
    }
    vector<vector<int>> mat = zeroMatrix(matrix, n, m);
    printMat(mat, n, m);

}