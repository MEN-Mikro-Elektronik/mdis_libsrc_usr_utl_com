/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *        \file  atox.c
 *
 *      \author  see
 *
 *     \project  UTL library
 *  	 \brief  Ascii (hex-format) to integer conversion
 *    \switches  none
 */
/*
 *---------------------------------------------------------------------------
 * Copyright (c) 1998-2019, MEN Mikro Elektronik GmbH
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
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <MEN/men_typs.h>
#include <stdio.h>
#include <MEN/usr_utl.h>

/**********************************************************************/
/** atox function
 *
 *  Ascii (hex-format) to integer conversion
 *
 *  \param str		\IN string with hex value
 *  \return			hex value as u_int32
 */
u_int32 UTL_Atox(char *str)
{
    u_int32 l;

    sscanf(str,"%lx",/*(unsigned int*)*/&l);
    return(l);
}
