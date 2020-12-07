/*
 *  Implementation of SAC standard module List
 */


#include "List.h"



int SAC_List_hd( SACarg * elems)
{
  list *data;

  data = (list *)SACARGgetSharedData (elems);
  if (data == NULL) {
    SAC_RuntimeError( "hd applied to NIL\n");
  }

  SACARGdeleteSacArray (&elems);

  return( data->elem);
}

