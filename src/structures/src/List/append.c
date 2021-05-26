/*
 *  Implementation of SAC standard module List
 */

#include "List.h"

#if 0

#define res_nt    (res,    T_OLD((SCL, (HID, (NUQ,)))))
#define elemsA_nt (elemsA, T_OLD((SCL, (HID, (NUQ,)))))
#define elemsB_nt (elemsB, T_OLD((SCL, (HID, (NUQ,)))))
#define new_nt    (new,    T_OLD((SCL, (HID, (NUQ,)))))

void SAC_List_append( SAC_ND_PARAM_out( res_nt, list *),
             SAC_ND_PARAM_in( elemsA_nt, list *),
             SAC_ND_PARAM_in( elemsB_nt, list *))
{
  SAC_ND_DECL__DESC( new_nt, )
  SAC_ND_DECL__DATA( new_nt, list *, )

  if (elemsA->rest == NULL) { /* elemsA == NIL! */
    SAC_ND_RET_out( res_nt, elemsB_nt)
    if (--(DESC_RC( elemsA->desc)) == 0) {
      SAC_List_free_list( elemsA);
    }
  }
  else {

    if (DESC_RC( elemsA->desc) == 1) { /* re-use all elems while (rc == 1)! */
      SAC_ND_RET_out( res_nt, elemsA_nt)

      do {
        new = elemsA;
        elemsA = elemsA->rest;
      }
      while ((elemsA->rest != NULL) && (DESC_RC( elemsA->desc) == 1));
      /*
       * Now, we decrement the "rest" of elemsA.
       * Although this may lead to a 0 rc in case of NIL,
       * we do NOT free that node, since we have to make
       * sure that it survives the copying while-loop.
       * After that loop we check, whether the rc is 0.
       * If that is the case, we know that there were
       * no copies to be done and we can free the NIL!
       */
      (DESC_RC( elemsA->desc))--;
#if TRACE
      fprintf( stderr, "changing CONS at (%p)\n", new);
#endif
    }

    else { /* copy first elem & decrement rc of 'elemsA'! */
      new = (list *) SAC_MALLOC( sizeof( list));
      new->elem = elemsA->elem;
      SAC_ND_ALLOC__DESC( new_nt, 0)
      SAC_ND_SET__RC( new_nt, 1)
      new->desc = SAC_ND_A_DESC( new_nt);
#if TRACE
      fprintf( stderr, "creating CONS at (%p)\n", new);
#endif
      SAC_ND_RET_out( res_nt, new_nt)
      (DESC_RC( elemsA->desc))--;

      elemsA = elemsA->rest; /* 'elemsA' has to be one in advance of 'new'! */
    }

    /*
     * 'new' points to the last elem reused/copied
     * 'elemsA' is one in front
     */
    while (elemsA->rest != NULL) {
      new->rest = (list *) SAC_MALLOC( sizeof( list));
#if TRACE
      fprintf( stderr, "       [ %d   .   (%p)]\n", new->elem, new->rest);
      fprintf( stderr, "creating CONS at (%p)\n", new->rest);
#endif
      new = new->rest;
      new->elem = elemsA->elem;
      SAC_ND_ALLOC__DESC( new_nt, 0)
      SAC_ND_SET__RC( new_nt, 1)
      new->desc = SAC_ND_A_DESC( new_nt);
      elemsA = elemsA->rest;
    }
    new->rest = elemsB;
#if TRACE
    fprintf( stderr, "       [ %d   .   (%p)]\n", new->elem, new->rest);
#endif
    /* Finally, we have to do some housekeeping! (see comment above!) */
    if (DESC_RC( elemsA->desc) == 0) {
      SAC_List_free_list( elemsA);
    }
  }
}

#undef res_nt
#undef elemsA_nt
#undef elemsB_nt
#undef new_nt

#endif
