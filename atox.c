/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *        \file  atox.c
 *
 *      \author  see
 *        $Date: 2009/07/22 13:26:55 $
 *    $Revision: 1.7 $
 *
 *     \project  UTL library
 *  	 \brief  Ascii (hex-format) to integer conversion
 *    \switches  none
 */
/*-------------------------------[ History ]---------------------------------
 *
 * $Log: atox.c,v $
 * Revision 1.7  2009/07/22 13:26:55  dpfeuffer
 * R: Generate doxygen documentation for MDIS5
 * M: file and function headers changed for doxygen
 *
 * Revision 1.6  2009/03/31 10:55:27  ufranke
 * cosmetics
 *
 * Revision 1.5  2008/01/18 13:55:45  ufranke
 * cosmetics
 *
 * Revision 1.4  2006/07/25 15:29:31  ufranke
 * cosmetics
 *
 * Revision 1.3  2005/06/30 10:45:32  UFranke
 * cosmetics
 *
 * Revision 1.2  1999/04/15 14:16:45  Franke
 * cosmetics
 *
 * Revision 1.1  1998/07/02 15:29:11  see
 * Added by mcvs
 *
 * cloned from S_UTILS lib
 *
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

char *UTL_atox_RCSid="$Id: atox.c,v 1.7 2009/07/22 13:26:55 dpfeuffer Exp $";

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
