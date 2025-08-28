#include "philo.h"

/*
    ./philo 5 800 200 200 [5]
    philo nbr, time to die, time to eat, time to sleep, nbr of meals 
    if the input is correct we kick in,
    otherways we tell the user to feed the right infos.
*/

int main(int ac, char **av)
{
    t_table table;

    if (ac == 5 || ac == 6 ) // correct input 
        parse_input(&table, av);
    else // error and exit
        error_exit("Wrong input");
}