/* lab -8 Breadth First Search I500/CSCI 609 */ 

#include <stdio.h>
#include <string.h>

#define MAX 50

/* structure of the flight database */
struct FLT {
  char from[20];
  char to[20];
  int distance;
  char skip; /* used for backtracking */
};

struct FLT flight[MAX]; /* array of flight db structures */

int fl_pos = 0;    /* number of entries in flight db */
int find_pos = 0; /* index for searching flight db */
int top_stack = 0;      /* top of stack */
struct stack {
  char from[20];
  char to[20];
  int dist;
} ;
struct stack bt_stack[MAX]; /* backtrack stack */

void setup(), route(char *to);
void insert_flight(char *from, char *to, int dist);
void push(char *from, char *to, int dist);
void pop(char *from, char *to, int *dist);
void is_flight(char *from, char *to);
int find(char *from, char *anywhere);
int match(char *from, char *to);

void main()
{
  char from[20], to[20];
  /*Create the flight Database.*/
  setup();
  printf("From?: ");
  gets(from);
 
  printf("Destination?: ");
  gets(to);  

  is_flight(from,to);
  route(to);

}

/* Initialize the flight database. */
void setup()
{
  insert_flight("New York", "Chicago", 1000);
  insert_flight("New York","Philadelphia",1200);
  insert_flight("Chicago", "Denver", 1000);
  insert_flight("New York", "Toronto", 800);
  insert_flight("New York", "Denver", 1900);
  insert_flight("Philadelphia","Boston",1500);
  insert_flight("Toronto", "Calgary", 1500);
  insert_flight("Toronto", "Los Angeles", 1800);
  insert_flight("Toronto", "Chicago", 500);
  insert_flight("Denver", "Urbana", 1000);
  insert_flight("Denver", "Houston", 1500);
  insert_flight("Houston", "Los Angeles", 1500);
  insert_flight("Denver", "Los Angeles", 1000);
}

/* Put Values into the database. */
void insert_flight(char *from, char *to, int dist)
{

  if(fl_pos < MAX) {
    strcpy(flight[fl_pos].from, from);
    strcpy(flight[fl_pos].to, to);
    flight[fl_pos].distance = dist;
    flight[fl_pos].skip = 0;
    fl_pos++;
  }
  else printf("Flight database full.\n");
}

/* Show the route and total distance. */
void route(char *to)

{
  int dist, t;

  dist = 0;
  t = 0;
  while(t < top_stack) {
    printf("%s to ", bt_stack[t].from);
    dist += bt_stack[t].dist;
    t++;
  }
  printf("%s\n", to);
  printf("Distance is %d.\n", dist);
}

/* If flight between from and to, then return the distance of flight; otherwise, return 0. */
int match(char *from, char *to)
{
   int t;

  for(t=fl_pos-1; t > -1; t--)
    if(!strcmp(flight[t].from, from) &&
      !strcmp(flight[t].to, to)) return flight[t].distance;

  return 0; /* not found */
}

/* Given from, find anywhere. */
int find(char *from, char *anywhere)
{
  find_pos = 0;
  while(find_pos < fl_pos) {
    if(!strcmp(flight[find_pos].from,from) &&
      !flight[find_pos].skip) {
        strcpy(anywhere,flight[find_pos].to);
        flight[find_pos].skip = 1; /* make active */
        return flight[find_pos].distance;
      }
    find_pos++;
  }
  return 0;
}

/* Determine if there is a route between from and to. */
void is_flight(char *from, char *to)
{
  int d, dist;
  char anywhere[20];
  
  /* see if at destination */ 
  if(d=match(from, to)) {
    push(from, to, d);
    return;
  } 
  while(dist=find(from, anywhere)) {
    /* breadth-first modification */
    if(d=match(anywhere, to)) {
      push(from, to, dist);
      push(anywhere, to, d);
      return;
    }
  }
  /* try any connection */ 
  if(dist=find(from, anywhere)) {
    push(from, to, dist);
    is_flight(anywhere, to);
  } 
  else if(top_stack>0) {
    pop(from, to, &dist);
    is_flight(from, to);
  }
}

/* Stack Routines */
void push(char *from, char *to, int dist)
{
  if(top_stack < MAX) {
    strcpy(bt_stack[top_stack].from,from);
    strcpy(bt_stack[top_stack].to,to);
    bt_stack[top_stack].dist = dist;
    top_stack++;
  }
  else printf("Stack Overflow...\n");
}

void pop(char *from, char *to, int *dist)
{
  if(top_stack > 0) {
    top_stack--;
    strcpy(from,bt_stack[top_stack].from);
    strcpy(to,bt_stack[top_stack].to);
    *dist = bt_stack[top_stack].dist;
  }
  else printf("Stack Underflow...\n");
}