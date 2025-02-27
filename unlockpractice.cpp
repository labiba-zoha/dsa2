#include<bits/stdc++.h>
using namespace std;
int minroa(int input,int unlock)
{
    int roat=0;
    int inputdigit,codedigit;
    while(input!=0||unlock!=0)
    {
        inputdigit=input%10;
        codedigit=unlock%10;
        int forwardrot=(codedigit-inputdigit+10)%10;
        int backwardrot=(inputdigit-codedigit+10)%10;
        roat+=min(forwardrot,backwardrot);
        input/=10;
        unlock/=10;

    }
    return roat;
}
int main()
{
    int input=28756;
    int unlock=98234;
    cout<<"minium roatation ="<<" "<<minroa(input,unlock);
}
