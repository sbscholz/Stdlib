/*****************************************************************
 *
 *  implementation of SAC standard library module Bits
 *
 *****************************************************************/

int SAC_Bits_BitTwosComplement(int val)
{
  return( (val ^ 0xFFFFFFFF) + 1);
}

/*****************************************************************/