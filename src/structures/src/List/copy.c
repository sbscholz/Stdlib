/*
 *  Implementation of SAC standard module List
 */

#include <stdio.h>

#include "sac.h"

#include "List.h"


list * SAC_List_copy_list( list *elems)
{
  list *new;

  if( empty (elems)) {
    new = NULL;
  } else {
#if TRACE
      fprintf( stderr, "copyin (%p)\n", (void *)elems);
#endif
    new = SAC_MALLOC (sizeof (list));
    new->rest = SAC_List_copy_list (elems->rest);
  }
  return new;
}
