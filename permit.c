/*********************  P r o g r a m  -  M o d u l e ***********************
 *
 *         Name: permit.c
 *      Project: UTL library
 *
 *       Author: ww
 *        $Date: 2014/10/29 12:03:39 $
 *    $Revision: 1.3 $
 *
 *  Description: UTL_Permit routine
 *
 *     Required:
 *     Switches:
 *
 *---------------------------[ Public Functions ]----------------------------
 *
 *-------------------------------[ History ]---------------------------------
 * $Log: permit.c,v $
 * Revision 1.3  2014/10/29 12:03:39  channoyer
 * R: Files for OS9 cant be compiled under QNX due to different errors
 * M: enclose whole code with #ifndef __QNX__
 *
 * Revision 1.2  2013/10/29 15:40:09  ts
 * R: Files for OS9 cant be compiled under VxWorks due to different errors
 * M: enclose whole code with #ifndef VXWORKS
 *
 * Revision 1.1  2012/12/05 10:55:09  ww
 * Initial Revision
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
static const char RCSid[]="$Header: /dd2/CVSR/COM/LIBSRC/USR_UTL/COM/permit.c,v 1.3 2014/10/29 12:03:39 channoyer Exp $";

#include    <types.h>
#include    <stdio.h>
#include    <modes.h>
#ifdef	OS9
#include	<process.h>
#endif

/**********************************************************************/
/** permit function
 *
 *  permit memory (ssm-module)
 *
 *  \param base		\IN char startpointer to memory
 *  \param size		\IN memory size
 *  \return error   error code
 */
int32
UTL_Permit( u_int8 *base, u_int32 size )
{
	u_int16	    pri,age,grp,usr;
	int32	    schedule;
	u_int32	    v_pid;
	error_code  error;
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
	if( (error = _os_permit( base, size, S_IREAD|S_IWRITE, v_pid ))&&error != 102 ) {
		fprintf(stderr,"can't get permit from kernel!; error: %d\n",error);
		return(error);
	}
	return(0);
}
#endif /* OS9000 */
