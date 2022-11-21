#include <iostream>
using namespace std;

void waiting_time(int process[], int n, int wait[], int burst[])
{

    wait[0]= 0;
    
    for (int i = 1; i < n; i++)
    {
        wait[i] = burst [i-1] + wait[i-1];
    }
    
}

void turnaround( int processes[], int n, int burst[], int wait[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = burst[i] + wait[i];
}

void avg(int process[], int n , int burst[]){

    int wait[n], tat[n], total_wt=0, total_turn=0;

    waiting_time(process, n, wait, burst);
    turnaround(process,n, burst, wait, tat);

    for (int i = 0; i < n; i++)
    {
        total_turn = total_turn + tat[i];
        total_wt = total_wt + wait[i];

    }
    
    cout<< "Avg turnaround time: "<<float(total_turn) / float(n) <<endl;
    cout<<"Avg waiting time: "<<float(total_wt)/ float (n)<<endl;
}

int main()
{
    int process[]= {1,2,3,4};
    int n = sizeof process / sizeof process[0];
    int burst []={5,4,2,10};
    avg(process, n, burst);
}