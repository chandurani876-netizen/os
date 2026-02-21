#include <stdio.h>

int main()
{
    int n = 5;

    int pid[5] = {1,2,3,4,5};
    int at[5]  = {0,1,2,3,4};
    int bt[5]  = {5,7,6,2,4};

    int ct[5], tat[5], wt[5];

    
    ct[0] = at[0] + bt[0];

    for(int i=1; i<n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    float avg_tat = 0, avg_wt = 0;

    
    for(int i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt  += wt[i];
    }

    avg_tat /= n;
    avg_wt  /= n;

    
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f", avg_wt);

    return 0;
}