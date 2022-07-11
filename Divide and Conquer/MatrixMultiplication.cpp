#include <cmath>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vi>
using namespace std;
/* finding next square of 2*/
int nextPowerOf2(int k)
{
    return pow(2, int(ceil(log2(k))));
}
// printing matrix
void display(vii C, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        cout << "|"
             << " ";
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << "|" << endl;
    }
}
//! addition and subtration
void add(vii &A, vii &B, vii &C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void sub(vii &A, vii &B, vii &C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
//!-----------------------------
void Strassen_algorithim(vii &A, vii &B, vii &C, int size)
{
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int newSize = size / 2;
        vi z(newSize);
        vii a(newSize, z), b(newSize, z), c(newSize, z), d(newSize, z),
            e(newSize, z), f(newSize, z), g(newSize, z), h(newSize, z),
            c11(newSize, z), c12(newSize, z), c21(newSize, z), c22(newSize, z),
            p1(newSize, z), p2(newSize, z), p3(newSize, z), p4(newSize, z),
            p5(newSize, z), p6(newSize, z), p7(newSize, z), fResult(newSize, z),
            sResult(newSize, z);
        int i, j;

        //! divide the matrix in equal parts
        for (i = 0; i < newSize; i++)
        {
            for (j = 0; j < newSize; j++)
            {
                a[i][j] = A[i][j];
                b[i][j] = A[i][j + newSize];
                c[i][j] = A[i + newSize][j];
                d[i][j] = A[i + newSize][j + newSize];

                e[i][j] = B[i][j];
                f[i][j] = B[i][j + newSize];
                g[i][j] = B[i + newSize][j];
                h[i][j] = B[i + newSize][j + newSize];
            }
        }
        /*
             A         B           C
           [a b]   * [e f]   =  [c11 c12]
           [c d]     [g h]      [c21 c22]
           p1,p2,p3,p4=AHED for this: A:Row(+) and B:Column(-)
           p5=Diagonal :both +ve
           p6=Last CR  :A:Row(-) B:Column(+)
           p7=First CR :A:Row(-) B:Column(+)
        */
        //! calculating all strassen formulas
        //*p1=a*(f-h)
        sub(f, h, sResult, newSize);
        Strassen_algorithim(a, sResult, p1, newSize);

        //*p2=h*(a+b)
        add(a, b, fResult, newSize);
        Strassen_algorithim(fResult, h, p2, newSize);

        //*p3=e*(c+d)
        add(c, d, fResult, newSize);
        Strassen_algorithim(fResult, e, p3, newSize);

        //*p4=d*(g-e)
        sub(g, e, sResult, newSize);
        Strassen_algorithim(d, sResult, p4, newSize);

        //*p5=(a+d)*(e+h)
        add(a, d, fResult, newSize);
        add(e, h, sResult, newSize);
        Strassen_algorithim(fResult, sResult, p5, newSize);

        //*p6=(b-d)*(g+h)
        sub(b, d, fResult, newSize);
        add(g, h, sResult, newSize);
        Strassen_algorithim(fResult, sResult, p6, newSize);

        //*p7=(a-c)*(e+f)
        sub(a, c, fResult, newSize);
        add(e, f, sResult, newSize);
        Strassen_algorithim(fResult, sResult, p7, newSize);

        /* calculating all elements of C by p1,p2,p3
        c11=p4+p5+p6-p2
        c12=p1+p2
        c21=p3+p4
        c22=p1-p3+p5-p7
        */
        add(p1, p2, c12, newSize); //!
        add(p3, p4, c21, newSize); //!

        add(p4, p5, fResult, newSize);
        add(fResult, p6, sResult, newSize);
        sub(sResult, p2, c11, newSize); //!

        sub(p1, p3, fResult, newSize);
        add(fResult, p5, sResult, newSize);
        sub(sResult, p7, c22, newSize); //!

        // Grouping the results obtained in a single matrix:
        for (i = 0; i < newSize; i++)
        {
            for (j = 0; j < newSize; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + newSize] = c12[i][j];
                C[i + newSize][j] = c21[i][j];
                C[i + newSize][j + newSize] = c22[i][j];
            }
        }
    }
}
/*for converting matrix to square matrix*/
void ConvertToSquareMat(vii &A, vii &B, int r1, int c1, int r2, int c2)
{
    int maxSize = max({r1, c1, r2, c2});
    int size = nextPowerOf2(maxSize);

    vi z(size);
    vii Aa(size, z), Bb(size, z), Cc(size, z);

    for (unsigned int i = 0; i < r1; i++)
    {
        for (unsigned int j = 0; j < c1; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }
    for (unsigned int i = 0; i < r2; i++)
    {
        for (unsigned int j = 0; j < c2; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }
    Strassen_algorithim(Aa, Bb, Cc, size);
    vi temp1(c2);
    vii C(r1, temp1);
    for (unsigned int i = 0; i < r1; i++)
    {
        for (unsigned int j = 0; j < c2; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }
    display(C, r1, c1);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    vii a = {
        {1, 2, 3},
        {1, 2, 3},
        {0, 0, 2}};
    vii b = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}};
    ConvertToSquareMat(a, b, 3, 3, 3, 3); // A[][],B[][],R1,C1,R2,C2
    return 0;
}