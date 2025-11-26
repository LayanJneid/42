#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

int is_rectangle(char **map)
{
    int i;
    int len_first;
    int len_current;

    i = 1;
    len_first= ft_strlen(map[0]);
    while (map[i])
    {
        len_current = ft_strlen(map[i]);
        if (len_current != len_first)
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char **map;
    map = store_rows("maps/map1.ber");
    if (!map)
        return 0;

    if (is_rectangle(map))
    {
         write (1,"valid",5);
    } 
    else 
        write (1,"invalid",7);

    // int i = 0;
    // while (map[i])
    //     free(map[i++]);
    // free(map);
    
    return 0;
}