#include<stdio.h>
int main()
{
int n;
printf("\n Enter number of Processes: ");
scanf("%d",&n);
int BT[n];
int AT[n],Fin[n],TAT[n],WT[n],temp,Process[n],i,j;
double avg_tat,avg_wt;
avg_tat=avg_wt=0;
for(i=0;i<n;i++)
Process[i]=i+1;
printf("\n Enter Burst Time: ");
for(int i=0;i<n;i++)
scanf("%d",&BT[i]);
printf("\n Enter Arrival Time: ");
for(int i=0;i<n;i++)
scanf("%d",&AT[i]);
for (i = 0; i < n - 1; i++)
for (j = 0; j < n - i - 1; j++)
if (AT[j] > AT[j + 1]){
//sorting AT
temp=AT[j];
AT[j]=AT[j+1];
AT[j+1]=temp;
//sorting BT
temp=BT[j];
BT[j]=BT[j+1];
BT[j+1]=temp;

//sorting process
temp=Process[j];
Process[j]=Process[j+1];
Process[j+1]=temp;
}
Fin[0]=AT[0]+BT[0];
for(i=1;i<n;i++)
{
Fin[i]=Fin[i-1]+BT[i];
}
printf("\n");
for(i=0;i<n;i++)
TAT[i]=Fin[i]-AT[i];
for(i=0;i<n;i++)
WT[i]=TAT[i]-BT[i];
printf("+-----------+-----------+-----------+-------------+-------------+-------------+\n");
printf("| Processes | Arrival | BurstTime |TurnAroundTime| WaitingTime | FinishTime
|\n");
printf("+-----------+-----------+-----------+-------------+-------------+-------------+\n");
for(i = 0; i < n; i++) {
printf("| %-9d | %-9d | %-9d | %-11d | %-11d | %-11d |\n", Process[i], AT[i], BT[i],
TAT[i], WT[i], Fin[i]);
printf("+-----------+-----------+-----------+-------------+-------------+-------------+\n");
}
printf("\n");
printf("\n\t Gantt Chart \n--------------------------------------------\n");
for(i=0;i<n;i++)
printf("|%d ",Process[i]);
printf("|");
printf("\n------------------------------------------");
printf("\n|%d",AT[0]);
for(i=0;i<n;i++)
printf(" |%d",Fin[i]);

printf(" |");
printf("\n");
for(i=0;i<n;i++)
avg_tat = avg_tat+(double)TAT[i];
avg_tat=avg_tat/n;
for(i=0;i<n;i++)
avg_wt = avg_wt+(double)WT[i];
avg_wt=avg_wt/n;
printf("\n Avg TAT:%lf",avg_tat);
printf("\n Avg Waiting Time:%lf",avg_wt);
avg_wt=avg_wt/4;
printf("\n");
}
