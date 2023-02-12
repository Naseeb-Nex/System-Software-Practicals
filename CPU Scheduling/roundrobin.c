#include <stdio.h>

struct process
{
    int wt;
    int bt;
    int pct;
    int cbt;
};

int main()
{
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    struct process p[n];
    printf("Enter the burst time of processes :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].bt);
        p[i].cbt = p[i].bt;
        p[i].wt = 0;
        p[i].pct = 0;
    }
    int t;
    printf("Enter the time qunta : ");
    scanf("%d", &t);
    int i = 0, count = 0, ct = 0;
    while (count != n)
    {
        if (p[i].bt == 0)
        {
            i = (i + 1) % n;
        }
        else if (p[i].bt > t)
        {
            p[i].bt -= t;
            p[i].wt = p[i].wt + (ct - p[i].pct);
            ct += t;
            p[i].pct = ct;
            i = (i + 1) % n;
        }
        else
        {
            p[i].wt = p[i].wt + (ct - p[i].pct);
            ct += p[i].bt;
            p[i].pct = ct;
            p[i].bt = 0;
            i = (i + 1) % n;
            count++;
        }
    }
    int tat[n], ttat = 0, twt = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = p[i].wt + p[i].cbt;
        twt += p[i].wt;
        ttat += tat[i];
    }

    printf("Average waiting time is %.2f", (float)twt / n);
    printf("\nAverage turnaround time is %.2f\n", (float)ttat / n);

    return 0;
}
