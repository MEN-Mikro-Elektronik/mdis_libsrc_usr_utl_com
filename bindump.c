/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *        \file  bindump.c
 *
 *      \author  see
 *
 *     \project  UTL library
 *  	 \brief  Binary dump routine
 *    \switches  none
 */
/*
 *---------------------------------------------------------------------------
 * Copyright 1998-2019, MEN Mikro Elektronik GmbH
 ******************************************************************************/
/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <MEN/men_typs.h>
#include <stdio.h>
#include <MEN/usr_utl.h>

/**********************************************************************/
/** Create binary dump string of long value
 *
 *  All nibbles are separated with blanks:\n
 *  bits=8:   'xxxx xxxx'\n
 *  bits=9: 'x xxxx xxxx'
 *
 *  \param  data    \IN value to dump
 *  \param  bits    \IN nr of bits (1..32)
 *  \param  buf     \OUT filled string buffer (size=40)
 *  \return			ptr to string buffer
 */
char *UTL_Bindump(u_int32 data, u_int32 bits, char *buf)
{
   u_int32 mask;
   char *sptr=buf;

   if (bits > 32)
	   bits = 32;

   mask = 1 << (bits-1);

   while(bits--) {
      if (sptr!=buf && bits && (bits+1)%4==0)   /* after 4 digits */
		  *sptr++ = ' ';             			/* insert blank */

      *sptr++ = ((data & mask) ? '1' : '0');
	  mask >>= 1;
   }

   *sptr = 0;                        /* terminator */
   return(buf);
}
