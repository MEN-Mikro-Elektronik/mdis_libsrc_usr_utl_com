/*********************  P r o g r a m  -  M o d u l e ***********************
 *
 *         Name: protect.c
 *      Project: UTL library
 *
 *       Author: ww
 *        $Date: 2014/10/29 12:04:43 $
 *    $Revision: 1.3 $
 *
 *  Description: UTL_Protect routine
 *
 *     Required:
 *     Switches:
 *
 *---------------------------[ Public Functions ]----------------------------
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2009 by MEN mikro elektronik GmbH, Nuremberg, Germany
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
#if defined(OS9000)
static const char RCSid[]="$Header: /dd2/CVSR/COM/LIBSRC/USR_UTL/COM/protect.c,v 1.3 2014/10/29 12:04:43 channoyer Exp $";

#include    <types.h>
#include    <stdio.h>
#include    <modes.h>
#ifdef	OS9
#include	<process.h>
#endif

/**********************************************************************/
/** protect function
 *
 *  protect memory (ssm-module)
 *
 *  \param base		\IN char startpointer to memory
 *  \param size		\IN memory size
 *  \return error   error code
 */
int32
UTL_Protect( u_int8 *base, u_int32 size )
{
	u_int16	    pri,age,grp,usr;
	int32	    schedule;
	u_int32	    v_pid;
	error_code   error;
#if	0
	if( error = _os9_id( &v_pid, &pri, &grp, &usr) ) {
		fprintf(stderr,"can't get process id!\n");
		return(error);
	}
#endif
	if( error = _os_id( &v_pid, &pri, &age, &schedule, &grp, &usr) ) {
		fprintf(stderr,"can't get process id!\n");
		return(error);
	}
	if( (error = _os_protect( base, size, S_IREAD|S_IWRITE, v_pid ))&&error != 102 ) {
		fprintf(stderr,"can't protect memory!; error: %d\n",error);
		return(error);
	}
	return(0);
}
#endif /* OS9000 */
