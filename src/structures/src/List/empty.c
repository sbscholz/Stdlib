/*
 *  Implementation of SAC standard module List
 */

#include "sac.h"

#include "List.h"


bool SAC_List_empty( SACarg *elems)
{
  bool res;

  res = (SACARGgetSharedData (SACTYPE_List__list, elems) == NULL);

  SACARGdeleteSacArray (&elems);

  return( res);
}


