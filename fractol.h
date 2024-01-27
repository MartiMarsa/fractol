#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx/mlx.h"

#define ERROR_MESSAGE "escribe bien los argumentos, primo.\n"


//utils

int	ft_strncmp(char *s1, char *s2, int n);
void	ft_putstr_fd(char *s, int fd);

//main

int	main(int argc, char **argv);

#endif