/*
** EPITECH PROJECT, 2018
** 101 pong
** File description:
** 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gestion_error(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	int k = 0;
	
	if (argc != 8)
		return (1);
	while (k != argc) {
		while (i != 8 && (argv[i][j] != 92 && argv[i][j+1] != '0')) {
			if (argv[i][j] > 57 || argv[i][j] < 48) {
				if (argv[i][j] == '-')
					j++;
				if (argv[i][j] < 48 || argv[i][j] > 57)
					return (1);
				j++;
			}
			i++;
			j = 0;
		}
		k++;
	}
	return (0);
}

int gestion_help(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0' && argc == 2) {
		printf("USAGE\n\t./101pong x0 y0 z0 x1 y1 z1 n\n\n");
		printf("DESCRIPTION\n\tx0\tball abscissa at time t - 1\n");
		printf("\ty0\tball ordinate at time t - 1\n");
		printf("\tz0\tball altitude at time t - 1\n");
		printf("\tx1\tball abscissa at time t\n");
		printf("\ty1\tball ordinate at time t\n");
		printf("\tz1\tball altitude at time t\n");
		printf("\tn\ttime shift (greater than or equal to zero, integer)\n");
		return (0);
	}
	else if (argc != 8)
		return (1);
	else if (argc == 8)
		return (2);
}


void display_success(char **argv, float resx1, float resy1, float resz1,
					float resx2, float resy2, float resz2, float result, float result1)
{
	printf("The velocity vector of the ball is:\n");
	printf("(%.2f, %.2f, %.2f)\n", resx1, resy1, resz1);
	printf("At time t + %d, ball coordinates will be:\n", (*argv[7] - 48));
	printf("(%.2f, %.2f, %.2f)\n", resx2, resy2, resz2);
	if ((*argv[3] > *argv[6] && *argv[6] > 0) || (*argv[3] < *argv[6] && argv[6] < 0)) {
		printf("The incidence angle is:\n");
		printf("%.2f degrees\n", result);
	}
	else
		printf("The ball won’t reach the bat.\n");
}

void calcul(char **argv)
{
	float resx1;
	float resy1;
	float resz1;
	float resx2;
	float resy2;
	float resz2;
	float result;
	float result1;
	float result2;
	

	resx1 = atof(argv[4]) - atof(argv[1]);
	resy1 = atof(argv[5]) - atof(argv[2]);
	resz1 = atof(argv[6]) - atof(argv[3]);
	resx2 = atof(argv[4]) + resx1 * (*argv[7] - 48);
	resy2 = atof(argv[5]) + resy1 * (*argv[7] - 48);
	resz2 = atof(argv[6]) + resz1 * (*argv[7] - 48);
	result1 = sqrt(pow(resx1, 2) + pow(resy1, 2));
	result2 = sqrt(pow(resx1, 2) + pow(resy1, 2) + pow(resz1, 2));
	result = acos(result1 / result2);
	result = result * (180/M_PI);
	display_success(argv, resx1, resy1, resz1, resx2, resy2, resz2, result, result1);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	
	j = gestion_error(argc, argv);
	i = gestion_help(argc, argv);
	if (i == 0)
		return (0);
	if (i == 1 || j == 1)
		return (84);
	if (i == 2 && j == 0) {
		calcul(argv);
	}
	return (0);
}
