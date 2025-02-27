int convert(int n)
{
    if(n==0)
        return 0;
    else
    {
        return((n%2)+10*convert(n/2));
    }
}
int countsetbits(int n)
{

    int count=0;//intize count wiht 0

    if(n==0)//base case no more digits
        return 0;

     if(n%10==1)//find the last digit if it is 1 then make cout 1;
        count=1;


    return count+countsetbits(n/10);//add the current count to the recursive call

}

int main()
{
    int n;
    printf("enter the decimal number");
    scanf("%d",&n);
    int x=convert(n);
    printf("the set bits count is %d",countsetbits(x));
}
