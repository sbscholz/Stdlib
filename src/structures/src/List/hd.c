/*
 *  Implementation of SAC standard module List
 */
#include <stddef.h>

#include "sac.h"

#include "List.h"



int SAC_List_hd( SACarg * elems)
{
  const list *data;
  int val;

  data = SACARGgetSharedData (SACTYPE_List__list, elems);
  if (data == NULL) {
    SAC_RuntimeError( "hd applied to NIL\n");
  }

  val = data->elem;

  SACARGdeleteSacArray (&elems);

  return( val);
}

