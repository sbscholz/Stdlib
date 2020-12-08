/*
 *  Implementation of SAC standard module List
 */

#include <stdio.h>

#include "sac.h"

#include "List.h"


SACarg *SAC_List_cons( int elem, SACarg * elems)
{
  list * res;

  res = SAC_MALLOC (sizeof (list));
  res->elem = elem;
  res->rest = SACARGgetUniqueData (SACTYPE_List__list, elems);

#if TRACE
  fprintf( stderr, "creating CONS at (%p)\n", (void *)res);
  fprintf( stderr, "       [ %d   .   (%p)]\n", elem, (void *)res->rest);
#endif

  SACARGupdateUniqueData (SACTYPE_List__list, elems, res);

  return elems;
}

