/*
** doble_malloc.c for yes in /home/josselin/EPITECH/machtstick/CPE_2016_matchstick
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Tue Feb 21 22:07:23 2017 Josselin
** Last update Tue Apr  4 12:13:29 2017 Josselin
*/

#include <stdlib.h>
#include "my.h"

char    **create_map(int l, int cl)
{
  char  **map;
  int   i;

  i = 0;
  map = malloc(sizeof(char *) * (l + 3));
  l = l + 3;
  while (l > 0)
    {
      map[i] = malloc(sizeof(char) + (cl + 1));
      i = i + 1;
      l = l - 1;
    }
  map[i + 1] = '\0';
  return (map);
}
