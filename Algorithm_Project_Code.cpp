#include<iostream>
#include<conio.h>
using namespace std;
int i,j;
struct Pair
{
    int w,tk;
    double profit;
};
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1]+ knapSack(W - wt[n - 1],wt, val, n - 1),knapSack(W, wt, val, n - 1));
}
void dp_knapsack()
{
    cout<<"Enter Total Number of Item : ";
    int m,i;
    cin>>m;
    int val[m],wt[m];
    cout<<"Enter The Amount of Items : ";
    for(i=0; i<m; i++)cin>>val[i];
    cout<<"Enter The Weight of Items : ";
    for(i=0; i<m; i++)cin>>wt[i];
    cout<<"Enter The Size of Knapsack : ";
    int W;
    cin>>W;
    int result = knapSack(W, wt, val, m);
    cout<<"Maximum Profit is = "<<result<<endl;
    cout<<"\n";
}
void Sort1(Pair p[],int n)
{
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(p[i].tk<p[j].tk)
            {
                swap(p[i].tk,p[j].tk);
                swap(p[i].w,p[j].w);
            }
        }
    }
}
void  knapsack_0_and_1()
{
    cout<<"Enter Total Number of Item : ";
    int n;
    cin>>n;
    Pair p[n];
    cout<<"Enter The Amount of Items : ";
    for(i=0; i<n; i++)cin>>p[i].tk;
    cout<<"Enter The Weight of Items : ";
    for(i=0; i<n; i++)cin>>p[i].w;
    Sort1(p,n);
    cout<<"Enter The Size of Knapsack : ";
    int W;
    cin>>W;
    int profit=0;
    i=0;
    while(W)
    {
        if(i==n)break;
        if(p[i].w<=W)
        {
            W-=p[i].w;
            profit+=p[i].tk;
        }
        i++;
    }
    cout<<"Maximum profit is = "<<profit<<endl;
    cout<<"\n";
}
void zero_one_knapsack()
{
    cout<<"Which Method You Want To Use : (Greedy/DP) : ";
    string st;
    cin>>st;
    if(st=="Greedy"||st=="greedy"||st=="GREEDY")
        knapsack_0_and_1();
    else
        dp_knapsack();
}
void Sort2(Pair p[],int n)
{
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(p[i].profit<p[j].profit)
            {
                swap(p[i].profit,p[j].profit);
                swap(p[i].tk,p[j].tk);
                swap(p[i].w,p[j].w);
            }
        }
    }
}
void fractional_knapsack()
{
    cout<<"Enter Total Number of Item : ";
    int n;
    cin>>n;
    Pair ar[n];
    cout<<"Enter The Amount of The Items : ";
    for(i=0; i<n; i++)
        cin>>ar[i].tk;
    cout<<"Enter The Weight of The Items : ";
    for(i=0; i<n; i++)
        cin>>ar[i].w;
    for(i=0; i<n; i++)
    {
        ar[i].profit=ar[i].tk/ar[i].w;
    }
    int Weight;
    cout<<"Enter The Size of Knapsack : ";
    cin>>Weight;
    Sort2(ar,n);
    i=0;
    float Profit=0;
    while(Weight!=0)
    {
        if(ar[i].w>=Weight)
        {
            Profit+=Weight*ar[i].profit;
            Weight=0;
        }
        else
        {
            Profit+=ar[i].tk;
            Weight-=ar[i].w;
        }
        i++;
    }
    printf("Maximum profit = %.2f\n",Profit);
    cout<<"\n";
}
int main()
{
    while(true)
    {
        cout<<"Welcome To our Algorithm project \n";
        cout<<"Filling The Shopping Cart \n\n\n";
        cout<<"Press  '1' To Work With Fractional Knapsack \n";
        cout<<"Press '2' To Work With  0/1 Knapsack  \n";
        cout<<"Press '0' To Exit \n";
        int n;
        cin>>n;
        if(n==1)
            fractional_knapsack();
        else if(n==2)
            zero_one_knapsack();
        else
            break;
    }
}
