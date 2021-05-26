#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int a, b,rest;
	printf("input A:");
	scanf("%d",&a);
	printf("input B:");
	scanf("%d", &b);
	rest = a / b;
	rest = a - b * rest;
	printf("remainder of the division A on B: %d",rest);

}