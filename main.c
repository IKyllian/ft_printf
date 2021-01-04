#include "ft_printf.h"

 int		main()
 {
// 	int nb = 42;
// 	char *str = "TEST";
// 	int c = 0;
// 	unsigned int u_nb = 10;
 	int res;
 	int res2;
// 	//float fnb = 52.48797979796;

// 	//res = ft_printf("Mine Printf test  - %010s - %-6i - %-05c - %0-----010p - %10u - %0000-0009x\n", str, nb, c, &c, u_nb, nb);
// 	//res2 = printf("Real Printf test  - %010s - %-6i - %-05c - %0----010p - %10u - %0000-00009x\n", str, nb, c, &c, u_nb, nb);

// 	//printf("Test flag : %-10d\n", nb);
 	 //res = ft_printf("Mine %-2.2d\n", 0);
 	 //res2 = printf  ("Real %-2.2d\n", 0);

	// res = ft_printf("Mine %*.s %.1s\n", 10, "123", "4567");
	// res2 = printf  ("Real %*.s %.1s\n", 10, "123", "4567");

	// res = ft_printf("Mine %*.0s %.2s\n", 10, "123", "4567");
	// res2 = printf  ("Real %*.0s %.2s\n", 10, "123", "4567");

	// res = ft_printf("Mine %*.3s %.3s\n", 10, "123", "4567");
	// res2 = printf  ("Real %*.3s %.3s\n", 10, "123", "4567");

	// res = ft_printf("Mine %*.4s %.4s\n", 10, "123", "4567");
	// res2 = printf  ("Real %*.4s %.4s\n", 10, "123", "4567");

	// res = ft_printf("Mine %10i %010i\n", 1, -1);
	 //res2 = printf  ("Real %10i %010i\n", 1, -1);

	//res = ft_printf("Mine %0*d\n", -4, -12);
	//res2 = printf  ("Real %0*d\n", -4, -12);

	// res = ft_printf("Mine %*.*s\n", 1, -2, "0");
	// res2 = printf  ("Real %*.*s\n", 1, -2, "0");

	// res = ft_printf("Mine %% *.5i 42 == |% *.5i|\n", 4, 42);
	// res2 = printf  ("Real %% *.5i 42 == |% *.5i|\n", 4, 42);
	
	//res = ft_printf("%-*.*i-%-*.*u-%-*.*x-%-*.*X-%-*.*s-%-*.*p-\n", 5, -20, -42, 5, -20, -42, 5, -20, -42, 5, -20, -42, 5, -20, "Test", 5, -20, &res);
	//res2 = printf  ("%-*.*i-%-*.*u-%-*.*x-%-*.*X-%-*.*s-%-*.*p-\n", 5, -20, -42, 5, -20, -42, 5, -20, -42, 5, -20, -42, 5, -20, "Test", 5, -20, &res);


	// res = ft_printf("%-20.30p\n", &str);
	// res2 = printf  ("%-20.30p\n", &str);

	//  res = ft_printf("%*.*p\n", -20, 30, NULL);
	//  res2 = printf  ("%*.*p\n", -20, 30, NULL);

	//0, -40, 0, 0, 89, NULL, NULL

	// res = ft_printf("Mine %-7.-4c-%-7.-4%-%-7.-4s\n", 89, "T");
	// res2 = printf  ("Real %-7.-4c-%-7.-4%-%-7.-4s\n", 89, "T");

	// res = ft_printf("Mine %*.*c-%*.*%-%*.*s\n", -7, -4, 89, -7, -4, -7, -4, "T");
	// res2 = printf  ("Real %*.*c-%*.*%-%*.*s\n", -7, -4, 89, -7, -4, -7, -4, "T");


	res = ft_printf("Mine %16.-10c-%16.-10i-%16.-10x-%16.-10u-%16.-10s-%16.-10p-%16.-10%\n", 0, 0, 0, 0, NULL, NULL);
	res2 = printf  ("Real %16.-10c-%16.-10i-%16.-10x-%16.-10u-%16.-10s-%16.-10p-%16.-10%\n", 0, 0, 0, 0, NULL, NULL);

	// res = ft_printf("Mine %*.i\n", 14, 42);
	// res2 = printf  ("Real %*.i\n", 14, 42);

	// printf("Res = %i\n", res);
	// printf("Res2 = %i\n", res2);
 	//res2 = printf(" *%-*.*i* *%*.*i* ", 6, 5, 10, 10, 21, -10);
 	printf("Res = %i\n", res);
	printf("Res2 = %i", res2);
 } //12 -- 14
 //13 -- 

