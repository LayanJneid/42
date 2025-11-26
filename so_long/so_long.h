#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h"
#include "get_next_line.h"

char **store_rows(char *filename);
int read_rows(char *filename);
void read_map_file(char *filename);
int check_extention(char *filename);
int is_rectangle(char **map);

#endif
