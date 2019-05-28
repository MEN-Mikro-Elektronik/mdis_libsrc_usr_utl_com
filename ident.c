/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *        \file  ident.c
 *
 *      \author  see
 *        $Date: 2013/11/14 17:23:10 $
 *    $Revision: 1.14 $
 *
 *     \project  UTL library
 *  	 \brief  USR_UTL global edition history
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
/** Return ident string of UTL module
 *
 *  \return			pointer to ident string
 */
char* UTL_Ident( void )
{
	return("UTL - User Utilities: %FSREV COM/LIBSRC/usr_utl 1.30 2013-11-14%");
}
