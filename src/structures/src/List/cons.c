/*
 *  Implementation of SAC standard module List
 */


#include "List.h"


SACarg *SAC_List_cons( int elem, SACarg * elems)
{
  list * res;

  res = (list *) SAC_MALLOC( sizeof( list));
  res->elem = elem;
  res->rest = (list *)SACARGgetUniqueData (elems);

#if TRACE
  fprintf( stderr, "creating CONS at (%p)\n", res);
  fprintf( stderr, "       [ %d   .   (%p)]\n", elem, res->rest);
#endif

  return SACARGupdateUniqueData (elems, (void *)res);
}

