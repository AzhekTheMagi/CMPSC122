
// Algorithm #3 aka Red Function


int Max_Subsequence_Sum_RED( const int A[], const int N )
{
  int This_Sum = 0, Max_Sum = 0;

  for (int Seq_End=0; Seq_End<N; Seq_End++)
  {
    This_Sum += A[Seq_End];

    if (This_Sum > Max_Sum)
    {
      Max_Sum = This_Sum;
    }
    else if (This_Sum < 0)
    {
      This_Sum = 0;
    }
  }
  return Max_Sum;
}

