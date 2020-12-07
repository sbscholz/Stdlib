/*
 *  Implementation of SAC standard module List
 */


#include "List.h"



SACarg *SAC_List_nil()
{
    SACarg *res;

    res = SACARGcreateFromPointer (SACTYPE_List__list, NULL, 0);

    return res;
}

