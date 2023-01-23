
// Algorithm #1 aka blue function. Code provided by CMPSC 122
// instructor.

int Max_Subsequence_Sum_BLUE( const int A[], const int N )
{
  int This_Sum = 0, Max_Sum = 0;

  for (int i=0; i<N; i++)
  {
    This_Sum = 0;
    for (int j=i; j<N; j++)
    {
      This_Sum += A[j];
      if (This_Sum > Max_Sum)
      {
        Max_Sum = This_Sum;
      }
    }
  }
  return Max_Sum;
}

