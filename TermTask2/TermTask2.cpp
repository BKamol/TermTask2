#include <iostream>
using namespace std;

void vvod_mat(double** mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
}
void vivod_mat(double** mat, int n, int m)
{
    cout << "-------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

void E(double** A, double** B, double** C, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n-1 || j == 0 || j == m-1)
            {
                C[i][j] = A[i][j] * B[i][j];
            }
            else
            {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    }
}

double F(double** mat, int n, int m)
{
    //Поиск минимальной суммы столбца матрицы
    double min_sum_stb = 0;
    for (int i = 0; i < n; i++)
    {
        min_sum_stb += mat[i][0];
    }

    for (int j = 1; j < m; j++)
    {
        double sum_stb = 0;
        for (int i = 0; i < n; i++)
        {
            sum_stb += mat[i][j];
        }
        if (sum_stb < min_sum_stb) min_sum_stb = sum_stb;
    }
    return min_sum_stb;
}

void recur(double** X, double** Y, int n, int m)
{
    //Рекурсивное вычисление матрицы X5
    for (int i = 0; i < 5; i++)
    {
        if (F(X, n, m) < F(Y, n, m))
        {
            E(X, Y, X, n, m);
        }
        else
        {
            E(Y, X, X, n, m);
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, m;
    cout << "Ввод n и m : " << endl;
    cin >> n >> m;

    //Инициализация матриц
    double** X = new double*[n];
    double** Y = new double*[n];
    for (int i = 0; i < n; i++)
    {
        X[i] = new double[m];
        Y[i] = new double[m];
    }

    cout << "Ввод элементов матрицы X: " << endl;
    vvod_mat(X, n, m);
    cout << "Ввод Элементов матрицы Y: " << endl;
    vvod_mat(Y, n, m);
    
    //Вызов рекурсивного вычисления X5
    recur(X, Y, n, m);
    //Вывод матрицы X5
    vivod_mat(X, n, m);


    //Удаление матриц
    for (int i = 0; i < n; i++)
    {
        delete[] X[i];
        delete[] Y[i];
    }
    delete[] X;
    delete[] Y;

}

