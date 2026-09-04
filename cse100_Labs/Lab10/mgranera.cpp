#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class matrix{
    private:
        int length;
    public:

        matrix();
        int MatrixChainMultiplication();
        void Print();
};

void Print(const vector<vector<int>>& s, int i, int j)
{
    if (i == j)
    {
        cout << "A" << j;
        return;
    }
    cout << "(";
    Print(s, i, s[i][j]);
    Print(s, s[i][j] + 1, j);
    cout << ")";
}

int MatrixChainMultiplication(const vector<int>& matrix, int n)
{
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int i = 2; i <= n; i++)
    {
        for (int l = 0; l <= n - i; l++)
        {
            int r = l + i - 1;
            m[l][r] = INT_MAX;

            for (int k = l; k < r; k++)
            {
                int q = m[l][k] + m[k + 1][r] + matrix[l] * matrix[k + 1] * matrix[r + 1];

                if (q >= m[l][r]) continue;
                
                m[l][r] = q;
                s[l][r] = k;
            }
        }
    }

    cout << m[0][n - 1] << "\n";
    Print(s, 0, n - 1);
    cout << "\n";

    return m[0][n - 1];
}

int main()
{
    int count;

    while (cin >> count)
    {
        vector<int> matrix(count + 1);

        for (int i = 0; i <= count; i++)
        {
            cin >> matrix[i];
        }

        MatrixChainMultiplication(matrix, count);
    }
    return 0;
}
