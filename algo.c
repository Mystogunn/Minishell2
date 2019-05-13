/*
** algo.c for algo.c in /home/josselin/EPITECH/MINISELL2/PSU_2016_minishell2
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Tue Apr  4 10:08:33 2017 Josselin
** Last update Tue Apr  4 10:28:33 2017 Josselin
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

int	algo(char **env)
{
  char	*enter;
  char	**arr;
  int	pid;

  enter = get_next_line(0);
  if (enter == NULL)
    return (-1);
  if (enter[0])
    return (-2);
  if (my_strcmp(enter, "exit") == 0)
    return (1);
  arr = my_str_to_wordtab(enter);
  free(enter);
  if (my_strcmp(arr[0], "cd") == 0)
    my_cd(arr, env);
  else
    {
      pid = my_exec(arr, env);
      wait(&pid);
      detect_signal_child(pid);
    }
  return (0);
}
