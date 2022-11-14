#define maxExp 100

#include <iostream>
#include <cmath>

using namespace std;

void multiplyQMatrices(int (*matrix1)[2], int (*matrix2)[2]) // fill the first matrix
{
  /*
   * |a0 a1|
   * |b0 b1|
   */
  int a0 = matrix1[0][0]*matrix2[0][0] + matrix1[0][1]*matrix2[1][0];
  int a1 = matrix1[0][0]*matrix2[0][1] + matrix1[0][1]*matrix2[1][1];
  int b0 = matrix1[1][0]*matrix2[0][0] + matrix1[1][1]*matrix2[1][0];
  int b1 = matrix1[1][0]*matrix2[0][1] + matrix1[1][1]*matrix2[1][1];
  
  matrix1[0][0] = a0;
  matrix1[0][1] = a1;
  matrix1[1][0] = b0;
  matrix1[1][1] = b1;
}

int main(int argc, char *argv[])
{
    int n;
    sscanf(argv[1], "%d", &n);
    int expansion[maxExp];
    int expansion_size = 0;
    if(n < 1)
    {
      cout << "Type error; n must be natural." << endl;;
      return -1;
    }
    n--;
    while(n > 0)
    {
      expansion[maxExp - expansion_size - 1] = n % 2; 
      n /= 2;
      expansion_size++;
    }
    
    int qMatrix[2][2] = {
                  {1,0},
                  {0,1}
                  };

    for(int i = maxExp - 1; i > maxExp - expansion_size - 1; i--)
    {
      if(expansion[i] == 1)
      {
        int qMatrix_tmp[2][2] = {
                  {1,1},
                  {1,0}
                  };
        for(int j = 0; j < maxExp - i - 1; j++)
        {
          multiplyQMatrices(qMatrix_tmp, qMatrix_tmp);
        }
        multiplyQMatrices(qMatrix, qMatrix_tmp);
      }
    }
    
    cout << qMatrix[0][1] << endl;
    return 0;
}
