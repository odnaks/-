#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

/*
	пример:
	10.25 = 1010.01 = 1.01001 * 2^3
	
	в коде:
	3 = x = e - 127;

	0 1000001.0 010010000..0
	  (01111111 + 11 = 10000010) 

	1. x << 1
	2. x & (255 << 24)
	3. x >> 24
	4. x - 127
	
	1. a << 8;
	2. a | (1 << 31);
	3. a >> (31 - x);
*/

void print_bit_m(int n, int m)
{
	int a;
	if (n & (1 << m))
		a = 1;
	else 
		a = 0;
	printf("%d", a);
}

void print_4_bit(int b)
{
	printf("\n");

	print_bit_m(b, 31);
	print_bit_m(b, 30);
	print_bit_m(b, 29);
	print_bit_m(b, 28);
	print_bit_m(b, 27);
	print_bit_m(b, 26);
	print_bit_m(b, 25);
	print_bit_m(b, 24);

	printf(" ");

	print_bit_m(b, 23);
	print_bit_m(b, 22);
	print_bit_m(b, 21);
	print_bit_m(b, 20);
	print_bit_m(b, 19);
	print_bit_m(b, 18);
	print_bit_m(b, 17);
	print_bit_m(b, 16);

	printf(" ");

	print_bit_m(b, 15);
	print_bit_m(b, 14);
	print_bit_m(b, 13);
	print_bit_m(b, 12);
	print_bit_m(b, 11);
	print_bit_m(b, 10);
	print_bit_m(b, 9);
	print_bit_m(b, 8);

	printf(" ");

	print_bit_m(b, 7);
	print_bit_m(b, 6);
	print_bit_m(b, 5);
	print_bit_m(b, 4);
	print_bit_m(b, 3);
	print_bit_m(b, 2);
	print_bit_m(b, 1);
	print_bit_m(b, 0);

	printf("\n");
}

int		is_one(int n, int a)
{
	if (n & (1 << (32 - a)))
		return (1);
	return (0);
}

unsigned int	pow_2(int n)
{
	unsigned int p;

	p = 1; 
	while (n > 0)
	{
		p *= 2;
		n--;
	}
	return (p);
}

unsigned int	pow_10(int n)
{
	unsigned int p;

	p = 1;
	while (n > 0)
	{
		p *= 10;
		n--;
	}
	return (p);
}

int main()
{
	float			f = 2.00078;
	unsigned int	fl = *(unsigned int*)&f;
	unsigned int	x = fl;
	unsigned int	a;
	unsigned int	b;
	long double		o = 0;

	x = (((x << 1) & (255 << 24)) >> 24) - 127;
	a = fl;
	a = ((a << 8) | (1 << 31)) >> (31 - x);
	b = fl;
	b = b << (x + 9);

	int i = 1;
	while (i < 32)
	{
		o += ((1 / (long double)pow_2(i)) * (long double)(is_one(b, i)));
		i++;
	}

	int toch = 6; //точность
	o *= (long double)pow_10(toch);
	b = (unsigned int)o;

	int nul = 0; //нули перед цифрами в остатке
	while ((!(int)(o / pow_10(toch - 1))))
	{
		nul++;
		toch--;
	}
	char nuls[nul];
	int n = 0;
	while (nul > 0)
	{
		nuls[n] = '0';
		n++;
		nul--;
	}
	nuls[n] = '\0';
	printf("float:		%f\n", f);
	printf("strings:	%s.%s%s\n", ft_itoa(a), nuls, ft_itoa(b));
	return (0);
}
