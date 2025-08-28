#include "philo.h"

static inline bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

static bool is_space(char c)
{
    return(c >= 9 && c <= 13 || c == 32);
}


/*
    check for negatives
    check if the nbr is legit
    check for INT_MAX
    Reurns a pointer to the actual number
    We clean everything before passing to ft_atol
*/
static const char *valid_input(const char *str)
{
    int len;
    const char *nbr;

    len = 0;
    while(is_space(*str))
        ++str;
    if (*str == '+')
        ++str;
    else if (*str == '-')
        error_exit("Feed me positive values");
    if(!is_digit(*str))
        error_exit("The input is not a correct digit");
    nbr = str;
    while (is_digit(*str++))
        ++len;
    if (len > 10)
        error_exit("INT_MAX");
    return (nbr);
}

/*
    alpha to long
*/
static long ft_atol(const char *str)
{
    long num;

    num = 0;
    str = valid_input(str);
    while(is_digit(*str))
        num = (num * 10) + (*str++ - 48);
    if (num > INT_MAX)
        error_exit("INT_MAX");
    return (num);
}


/*
timestamps are given in milliseconds
but usleep function want microseconds

 ./philo   5      800     200     200     [5]   
        av[1]   av[2]   av[3]   av[4]   av[5]
        i want to convert the av in integers
        check if: the string are actual numbers
            no > INT_MAX
            timestamps > 60ms milliseconds
        but usleep wants microseconds
        
*/
void parse_input(t_table *table, char **av)
{
    table->philo_nbr = ft_atol(av[1]); 
    table->time_to_die = ft_atol(av[2]) * 1000; // we convert in microseconds
    table->time_to_eat = ft_atol(av[3]) * 1000;
    table->time_to_sleep = ft_atol(av[4]) * 1000;
    if (table->time_to_die < 6e4 
        || table->time_to_eat < 6e4
        || table->time_to_sleep < 6e4)
        error_exit("Use taimestamps major then 60ms");
    if (av[5])
        table->nbr_limit_meals = ft_atol(av[5]);
    else
        table->nbr_limit_meals = -1;
}