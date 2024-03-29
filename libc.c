/*
 * libc.c 
 */

#include <libc.h>

#include <types.h>

int errno;

void itoa(int a, char *b)
{
  int i, i1;
  char c;
  
  if (a==0) { b[0]='0'; b[1]=0; return ;}
  
  i=0;
  while (a>0)
  {
    b[i]=(a%10)+'0';
    a=a/10;
    i++;
  }
  
  for (i1=0; i1<i/2; i1++)
  {
    c=b[i1];
    b[i1]=b[i-i1-1];
    b[i-i1-1]=c;
  }
  b[i]=0;
}

int strlen(char *a)
{
  int i;
  
  i=0;
  
  while (a[i]!=0) i++;
  
  return i;
}

void perror()
{
  char buffer[256];

  itoa(errno, buffer);

  write(1, buffer, strlen(buffer));
}

int m;
void prova_mutex(){
  mutex_init(&m);
  create_thread(inner_prova_mutex, 1);
  inner_prova_mutex(0);
}

void inner_prova_mutex(int p) {
  int vector_size = 100;
  int time_delay = 100000;
  int v[vector_size];
  mutex_lock(&m);
  if (p==0) {
    write(1, "Soy P1\n", 7);
    for (int delay = 0; delay < time_delay; ++delay)
    for (int i = 0; i < vector_size; ++i) 
      v[i] = i;
    write(1, "P1 done\n", 8);
  } else {
    write(1, "Soy P2\n", 7);
    for (int delay = 0; delay < time_delay; ++delay)
    for (int i = 0; i < vector_size; ++i)
      v[i]--;
    write(1, "P2 done\n", 8);
  }
  mutex_unlock(&m);
}
