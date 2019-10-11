#include<stdio.h>
#include<random>>
#define N 10

void printIntBin(int value)
{
	for (int i = 31; i >=0; i--)
	{
		printf(((value&(1<<i))==0)?"0":"1");
	}
	printf("\n");
}

int Task(int value)
{
	int tmp = value & (0x00FFFF00);
	for (int i = 0; i < 8; i++)
	{
		tmp += ((value & (1 << i)) >> i) << (7 - i);
		tmp += ((value & (1 << (31 - i))) << i) >> (7 - i);
	}
	return tmp;
}

int main()
{
	/*  Задание
	 *  Зеркально поменять местами разряды внутри старшего и младшего байтов каждого числа. 
	 *  Найти кол-во четных чисел до и после замены.
	 */

	int intArray[N];
	int evenNumbers = 0;

	for (int i = 0; i < N; i++)
	{
		intArray[i] = rand() % 1000000000 - 500000000;
		if (intArray[i] % 2 == 0) evenNumbers++;
		printf("intArray[%d] = %d\n", i, intArray[i]);
		printIntBin(intArray[i]);
	}
	printf("%d even numbers before replace\n", evenNumbers);

	evenNumbers = 0;
	for (int i = 0; i < N; i++)
	{
		intArray[i] = Task(intArray[i]);
		if (intArray[i] % 2 == 0) evenNumbers++;
		printf("intArray[%d] = %d\n", i, intArray[i]);
		printIntBin(intArray[i]);
	}
	printf("%d even numbers after replace\n", evenNumbers);
	return 0;
}