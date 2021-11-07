#include "minitalk.h"
#include <stdio.h>

int g_size;

void    char_put(int bit)
{
    static char c;

    c += ((bit & 1) << g_size);
    g_size++;
    if (g_size == 7)
    {
        write(1, &c, 1);
        if (!c)
            write(1, "\n", 1);
        g_size = 0;
        c = 0;
    }
}

int get_digit(int num)
{
    int i;

    i = 0;
    while(num != 0)
    {
        num /= 10;
        i++;
    }
    return (i);
}

char *ft_itoa(int num, int digit)
{
    char	*s;
	int		i;

	if (digit == 0)
		return (NULL);
	s = malloc(digit + 1);
	if (!s)
		return (NULL);
	i = digit - 1;
	while (i >= 0)
	{
		s[i] = num % 10 + '0';
		num /= 10;
		i -=1;
	}
	s[digit] = '\0';
	return (s);
}

int main() {
    int     pid;
    char    *str_id;
    int     digit;

    g_size = 0;
    pid = getpid();
    digit = get_digit(pid);
    str_id = ft_itoa(pid, digit);
    if(!str_id)
        exit(1);
    write(1, str_id, digit);
    write(1, "\n", 1);
    free(str_id);
    while(1)
    {
        signal(SIGUSR1,char_put);
        signal(SIGUSR2,char_put);
        pause();
    }
    return (0);
}