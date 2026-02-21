#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt1[n], io[n], bt2[n];
    int ct[n], tat[n], wt[n];
    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("First CPU Burst (BT1): ");
        scanf("%d", &bt1[i]);
        printf("I/O Time: ");
        scanf("%d", &io[i]);
        printf("Second CPU Burst (BT2): ");
        scanf("%d", &bt2[i]);
    }
    int time = 0;
    for(i = 0; i < n; i++) {
        if(time < at[i])
            time = at[i];
        time += bt1[i];
        time += io[i];
        time += bt2[i];
        ct[i] = time;
    }
    float total_tat = 0, total_wt = 0;
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - (bt1[i] + bt2[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("\nPID\tAT\tBT1\tIO\tBT2\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i, at[i], bt1[i], io[i], bt2[i],
        ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    return 0;
}