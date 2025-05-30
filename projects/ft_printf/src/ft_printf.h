#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *format, ...);

// Formatting functions
int		print_char(char c);
int		print_string(char *s);
int		print_pointer(void *p);
int		print_integer(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned int n, char spec);

// String utils
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

// Print utils
int		ft_putstr(char *s);
int		ft_putnbr(int n, int *count);
int		ft_putchar(char c);

// Utilities
char	*utoa(unsigned int n);
char	*number_to_hex(uintptr_t num, const char *base);

#endif
