#define SIZE 10
#include <stdio.h> 
void print(int *a, int n)
{
      int i;
         for (i = 0; i < n; i++)
             printf("%d\t", a[i]);
}

// radix sort function
void radixsort(int *a, int n)
{
        int i, b[SIZE], m = 0, exp = 1;
                for (i = 0; i < n; i++)
                 {
                     if (a[i] > m)
                       m = a[i];
                 }
           while (m / exp > 0)
            {      // Initialize 10 buckets with 0
                   int bucket[10] = {0};

               for (i = 0; i < n; i++)
                  bucket[a[i] / exp % 10]++; // extracting the digits
               for (i = 1; i < 10; i++)
                  bucket[i] += bucket[i - 1];
               for (i = n - 1; i >= 0; i--)
                  b[--bucket[a[i] / exp % 10]] = a[i];
               for (i = 0; i < n; i++)
                  a[i] = b[i];
                  exp *= 10;     
               for (i = 1; i < n; i++){ 
                printf("\nPASS[%d] : ",i);
                print(a, n);
               }
            }
}
void main(int argc, char* argv [])
{
	int data[SIZE];
        int d = 0;
        for (d= 0; d < SIZE; d++)
        {
                data[d]=0;
        }

    
    if(argc <2)
    {
                int i =0;
                int j = SIZE;

                printf("Please type %d digitals here, each number a line\n",j);
                for(i =0; i< SIZE; i++)
                {
                        scanf("%d",&data[i]);
                }
    }
    else if(argc ==2) // file reading
    {
                int c=0;
                FILE *fp = fopen(argv[1],"r");
                int m = 0;
                while(fscanf(fp,"%d",&data[m++])!= EOF);
               
    }
printf("\nARRAY : ");
print(&data[0], SIZE);
radixsort(&data[0], SIZE);
printf("\nSORTED : ");
print(&data[0], SIZE);
printf("\n");

}