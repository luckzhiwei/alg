#include <iostream>
using namespace std;

const int N = 4;
static int num = 0;

int a[N][N] = {0};

//输出矩阵
void print(int a[][N],int row); //注意二维数组如何调用
//判断步骤是否有效
bool is_valid(int i, int j);
//探索，遍历
void traversal(int i);

int main()
{
    traversal(0);
    cout << "There are " << num << " solutions for eight queens problems" <<endl;
    return 0;
}

//探索，遍历(核心部分)
void traversal(int i)
{
    if(i >= N)
    {
        print(a, N);
    }
    for(int j = 0; j != N; ++j)
    {
        a[i][j] = 1;
        if(is_valid(i,j)) traversal(i+1);
        a[i][j] = 0;
    }
}

//判断步骤是否有效
bool is_valid(int i, int j)
{
    bool b = true;
    for(int i1 = 0; i1 != i; ++i1)
        for(int j1 = 0; j1 != N; ++j1)
        {
            if(a[i1][j1] == 1)
                if((j1 == j) || ( abs(i1 - i) == abs(j1 - j)) ) b = false;
        }
    return b;
}

//输出矩阵
void print(int a[][N],int row)
{
    ++num;
    for(int i = 0; i != row; ++i)
    {
        for(int j = 0; j != N; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << "--------------------" <<endl;
}