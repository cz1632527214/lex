#include<stdio.h>
int main()
{
	char str1[] = "3+4";  //���׼�����V0 
	int a, b;
	a = str1[0] - '0';
	b = str1[2] - '0';
	printf("V0:3+4=%d\n\n", a + b);


	char str2[] = "1+2+2+1+2+5+4-1-3+4-8";//���׼�����V1
	int i, sum;
	sum = str2[0] - '0';
	for (i = 1; str2[i] != '\0'; i++)
	{
		if (str2[i] == '+' || str2[i] == '-')
		{
			switch (str2[i])
			{
			case '+':sum=sum + (str2[i+1] - '0'); break;
			case '-':sum=sum - (str2[i+1] - '0'); break;
			}
		}
	}
	printf("V1:1+2+2+1+2+5+4-1-3+4-8=%d\n\n", sum);


	char str3[] = "2*2/4*1/1*2*3/2"; //���׼�����V2
	int result;
	result = str3[0] - '0';
	for (i = 1; str3[i] != '\0'; i++)
	{
		if (str3[i] == '*' || str3[i] == '/')
		{
			switch (str3[i])
			{
			case '*':result = result * (str3[i + 1] - '0'); break;
			case '/':result = result / (str3[i + 1] - '0'); break;
			}
		}
	}
	printf("V2:2*2/4*1/1*2*3/2=%d\n\n", result);





	char str4[] = "2+2*3+2/2-1";//���׼�����V3
	int j;
	float fruit;
	fruit = float(str4[0] - '0');
	for (j = 1; str4[j] != '\0'; j++)
	{
		if (str4[j] == '+')
		{
			if (str4[j + 2] == '*' || str4[j + 2] == '/')
			{
				switch (str4[j + 2])
				{
				case '*':fruit = fruit + float(str4[j + 1] - '0')*float(str4[j + 3] - '0'); break;
				case '/':fruit = fruit + float(str4[j + 1] - '0') / float(str4[j + 3] - '0'); break;
				}
			}
			else
			{
				fruit = fruit + (str4[j + 1] - '0');
			}
		}

		else if (str4[j] == '-')
		{
			if (str4[j + 2] == '*' || str4[j + 2] == '/')
			{
				switch (str4[j + 2])
				{
				case '*':fruit = fruit - float(str4[j + 1] - '0')*float(str4[j + 3] - '0'); break;
				case '/':fruit = fruit - float(str4[j + 1] - '0')/float(str4[j + 3] - '0'); break;
				}
			}
			else
			{
				fruit = fruit - (str4[j + 1] - '0');
			}
		}
	}
	printf("V3:2+2*3+2/2-1=%.2f\n",fruit);
	return 0;
}