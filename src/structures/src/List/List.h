#ifndef _STDLIB_LIST_H_
#define _STDLIB_LIST_H_
/*
 *  Implementation of SAC standard module List
 */

#define TRACE 1

#include "sacinterface.h"

extern SACtypes *SACTYPE_List__list;

typedef struct LIST {
  int                    elem;
  struct LIST            *rest;
} list;


extern list * SAC_List_free_list( list *elems);
extern list * SAC_List_copy_list( list *elems);

extern SACarg *nil ();
extern SACarg *cons (int elem, SACarg *rest);
extern int     hd (SACarg *elems);
extern SACarg *tl (SACarg *elems);


#endif
