/*
** main.c for main.c in /home/josselin/EPITECH/Get_next/bootstrap
**
** Made by Josselin
** Login   <josselin.cosmao@epitech.eu>
**
** Started on  Tue Jan  3 17:04:59 2017 Josselin
** Last update Wed Apr  5 18:05:18 2017 Josselin
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

void	my_signal(int sign)
{
  char *prompt;

  if (sign == SIGINT)
    {
      prompt = get_prompt();
      if (prompt == NULL)
	my_putstr("> ");
      else
	{
	  my_putstr(prompt);
	  my_putstr("> ");
	}
    }
}

void	detect_signal_child(int pid)
{
  if (WIFSIGNALED(pid))
  {
    if (WTERMSIG(pid) == SIGSEGV)
      my_putstr("Segmentation fault (core dumped)\n");
  }
}

char	*get_prompt()
{
  char	*buf;
  char	*prompt;
  int	i;

  if (((buf = malloc(sizeof(char) * 4096)) == NULL)
      || (buf = getcwd(buf, 4096)) == NULL
      || (prompt = malloc(sizeof(char) * 4096)) == NULL)
    return (NULL);
  i = 0;
  while (buf[i] != 0)
    {
      prompt[i] = buf[i];
      i = i + 1;
    }
  prompt[i] = 0;
  return (prompt);
}

int	main(int ac, char **av, char **env)
{
  char	*enter;
  char	*prompt;
  char	**arr;
  char	**copy_env;
  int	pid;

  copy_env = new_env(env);
  signal(SIGINT, my_signal);
  while (1)
    {
      prompt = get_prompt();
      if (prompt != NULL)
	{
	  my_putstr(prompt);
	  my_putstr("> ");
	}
      else
	my_putstr("> ");
      enter = get_next_line(0);
      if (enter == NULL)
	exit(0);
      if(enter[0] == 0)
	continue;
      if (my_strcmp(enter, "exit") == 0)
	break;
      arr = my_str_to_wordtab(enter);
      if (my_strcmp(arr[0], "cd") == 0)
	my_cd(arr, env);
      else if (((my_strcmp(arr[0], "env") == 0) && arr[1] == NULL) ||
	       ((my_strcmp(arr[0], "setenv") == 0) && arr[1] == NULL))
	print_tab(copy_env);
      else
	{
	  pid = my_exec(arr, env);
	  wait(&pid);
	  detect_signal_child(pid);
	}
    }
  my_putstr("exit\n");
  return (0);
}
