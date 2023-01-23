
// Algorithm #2 aka Green Function

int Max_Subsequence_Sum_GREEN( const int A[], const int N )
{
  int This_Sum = 0, Max_Sum = 0;

  for (int i=0; i<N; i++)
  {
    for (int j=i; j<N; j++)
    {
      This_Sum = 0;
      for (int k=i; k<=j; k++)
      {
        This_Sum += A[k];
      }
      if (This_Sum > Max_Sum)
      {
        Max_Sum = This_Sum;
      }
    }
  }
  return Max_Sum;
}

