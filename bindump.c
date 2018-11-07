/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *        \file  bindump.c
 *
 *      \author  see
 *        $Date: 2009/07/22 13:26:57 $
 *    $Revision: 1.6 $
 *
 *     \project  UTL library
 *  	 \brief  Binary dump routine
 *    \switches  none
 */
/*
 *---------------------------------------------------------------------------
 * Copyright (c) 1998 MEN Mikro Elektronik GmbH. All rights reserved.
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

char UTL_bindump_RCSid[]="$Id: bindump.c,v 1.6 2009/07/22 13:26:57 dpfeuffer Exp $";

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
