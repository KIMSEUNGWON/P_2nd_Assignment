#include<stdio.h>
#include<math.h>
int checkPrimeNumber(int n);
int checkArmstrongNumber(int n);
int checkPrime(int n);
int main(void)
{
	int n,n1,n2,i,flag,select;
	
	printf("you can choose numbers from 1,2 and 3.\n");
	printf("if you choose number 1, you can get Prime Numbers Between intervals.\n");
	printf("if you choose number 2, you can get Prime or Armstron Number.\n");
	printf("if you choose number 3, you can get the number whether a Number can be expressed 					as Sum of two Prime Number.\n");
	printf("which one do you choose from 1,2 and 3?\n");
	scanf("%d",&select);
	
	if(select==1)
	{
		printf("Enter two positive integers: ");
		scanf("%d%d",&n1,&n2);
		printf("prime numbers between %d and %d are: ",n1,n2);

		for(i=n1+1;i<n2;++i)
		{
			flag =checkPrimeNumber(i);
		
				if(flag==1)
					printf("%d ",i);
		}

	}
	else if(select==2)
	{
		printf("Enter a positive integer: ");
		scanf("%d",&n);

	flag=checkPrimeNumber(n);
	if(flag ==1)
		printf("%d is a PrimeNumber.\n",n);
	else
		printf("%d is not a PrimeNumber.\n",n);
	
	flag=checkArmstrongNumber(n);
	if(flag ==1)
		printf("%d is an ArmstrongNumber.\n",n);
	else
		printf("%d is not an ArmstrongNumber.\n",n);


	}
	else if(select==3)
	{
		 printf("Enter a positive integer: ");
   		 scanf("%d", &n);

    
	for(i=2;i<=n/2;++i)
		{
			
			
			if (checkPrime(i) == 1)
			{
				
				if (checkPrime(n-i)== 1)
				{
					printf("%d = %d +%d\n",n,i,n-i);
					flag =1;
					
				}
			}


		}

    if (flag == 0)
        printf("%d cannot be expressed as the sum of two prime numbers.", n);
	}
	
	else
	{
		printf("you have to choose from 1,2and3.\n");
	}

	return 0;

}



int checkPrimeNumber(int n)
{
	
	int j,flag=1;
	for(j=2;j<=n/2;++j)
		{
			if(n%j==0)
			{
				flag =0;
				break;
			}
		}

		return flag;
}

int checkArmstrongNumber(int number)
{
	
	int originalNumber, remainder, result = 0, n =0, flag;
	originalNumber = number;
	while (originalNumber != 0)
	{
		
		originalNumber /= 10;
		++n;
		
	}
		
	originalNumber = number;

	while (originalNumber !=0)
	{
		remainder = originalNumber%10;
		result += pow(remainder, n);
		originalNumber /= 10;
	}

	
	if(result == number)
		flag =1;
	else
		flag =0;
	return flag;

}

int checkPrime(int n)
{

	int i, flag = 1;    
		for(i=2; i<=n/2; ++i)    
		{    
		       
			if(n%i == 0)        
			{            
				flag = 0;            
				break;        
			}    
		}    
		return flag;

}