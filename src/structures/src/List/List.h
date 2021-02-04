#ifndef _STDLIB_LIST_H_
#define _STDLIB_LIST_H_
/*
 *  Implementation of SAC standard module List
 */

#define TRACE 1

#include <stdbool.h>
#include "sacinterface.h"

extern SACtypes *SACTYPE_List__list;

typedef struct LIST {
  int                    elem;
  struct LIST            *rest;
} list;


extern list * SAC_List_free_list (list *elems);
extern list * SAC_List_copy_list (list *elems);

extern SACarg *SAC_List_nil (void);
extern SACarg *SAC_List_cons (int elem, SACarg *rest);
extern int     SAC_List_hd (SACarg *elems);
extern SACarg *SAC_List_tl (SACarg *elems);
extern bool    SAC_List_empty ( SACarg *elems);


#endif
