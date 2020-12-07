/*
 *  Implementation of SAC standard module List
 */


#include "List.h"


SACarg * SAC_List_tl( SACarg * elems)
{
  list *data, *tail;

  data = SACARGgetUniqueData (SACTYPE_List__list, elems);
  
  if (data == NULL) {
    SAC_RuntimeError( "tl applied to NIL\n");
  }

  tail = data->rest;
  data = SAC_FREE (data); 

  SACARGupdateUniqueData (SACTYPE_List__list, elems, tail);

  return elems;

}
