#include <unistd.h>
#include <fcntl.h>
#include "so_long.h"
#include <stdio.h>


int check_extention(char *filename)
{
    int i;
    //dksfffffffffffffffff
    i = 0;
    while(filename[i])
        i++;
    if (i >= 4 && filename[i-1] == 'r' &&
         filename[i-2] == 'e' && 
         filename[i-3] == 'b' &&
          filename[i- 4] == '.')
        return 1 ;
    else
        return 0;
}
void read_map_file(char *filename)
{
    int fd;
    char *line;

    if (!check_extention(filename))
    {
        write(1,"invalid extention",17);
        return;
    }
    fd = open(filename, O_RDONLY); 
    if (fd < 0)
    {
        write(1,"Error!\n",7);
        return;
    }
    
    write (1,"file opened!\n",13); 
    line = get_next_line(fd);
        while (line)
        {
            printf("%s",line);
            free(line);
            line = get_next_line(fd);
        }      
        close(fd);
     }
int read_rows(char *filename)
{
    int fd;
    char *line;
    int rows;
    
    rows = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return 0;
    line = get_next_line(fd);
    while (line)
        {
            free(line);
            rows++;
            line = get_next_line(fd);
            
        }      
        close(fd);
        return (rows);
}
char **store_rows(char *filename)
{
    int rows;
    int i;
    int fd;
    char **map;

    i= 0;
    rows = read_rows(filename);
    if (rows == 0)
        return NULL;
    map = malloc(sizeof(char *) * (rows + 1));
    if (!map)
        return NULL;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return NULL;
    }
    while (i < rows)
        map[i++] = get_next_line(fd);
    map[i] = NULL;
    close(fd);
    return map;
}
// int main()
// {
//     // read_map_file("maps/map1.ber");
//     //check_extention("maps/map1.ber");
//     // check_extention("file.txt");
//     read_map_file("file.txt");
//     //printf("%d",read_rows("maps/map1.ber"));

//     // char **map = store_rows("maps/map1.ber");
//     // int i = 0;

//     // while (map && map[i])
//     //     printf("%s", map[i++]);

//     // i = 0;
//     // while (map && map[i])
//     //     free(map[i++]);
//     // free(map);

//     return 0;
// }


