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


	// res = ft_printf("%.50p\n", &res);
	// res2 = printf  ("%.50p\n", &res);

	// res = ft_printf("%30.*p\n", 20, &res);
	// res2 = printf  ("%30.*p\n", 20, &res);
	
	res = ft_printf("%30.13p\n", &res);
	res2 = printf  ("%30.13p\n", &res);

	//0, -40, 0, 0, 89, NULL, NULL

	//res = ft_printf("Mine %10.s -%02.s\n", "123", "4567");
	//res2 = printf  ("Real %10.s -%02.s\n", "123", "4567");

	//res = ft_printf("Mine *%-*.*i* *%*.*i*\n",4, 5, 10, 10, 21, -10);
	//res2 = printf  ("Real *%-*.*i* *%*.*i*\n", 4, 5, 10, 10, 21, -10);

	// printf("Res = %i\n", res);
	// printf("Res2 = %i\n", res2);
	// res = ft_printf("Mine 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);
	// res2 = printf  ("Real 0*%0-*.*d*0 0*%0*.*d*0\n", 2, 6, 102, 21, 10, -101);
 	//res2 = printf(" *%-*.*i* *%*.*i* ", 6, 5, 10, 10, 21, -10);
 	printf("Res = %i\n", res);
	printf("Res2 = %i", res2);
 }
 