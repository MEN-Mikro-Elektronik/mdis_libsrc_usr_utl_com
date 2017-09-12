#***************************  M a k e f i l e  *******************************
#
#         Author: see
#          $Date: 2012/12/05 10:57:13 $
#      $Revision: 1.3 $
#
#    Description: Makefile descriptor file for USR_UTL lib
#
#---------------------------------[ History ]---------------------------------
#
#   $Log: library.mak,v $
#   Revision 1.3  2012/12/05 10:57:13  ww
#   added permit.c, protect.c and log.c.
#
#   Revision 1.2  1998/09/09 10:01:07  Schmidt
#   sourcefile ident.c added
#
#   Revision 1.1  1998/07/02 15:29:09  see
#   Added by mcvs
#
#-----------------------------------------------------------------------------
#   (c) Copyright 1998 by MEN mikro elektronik GmbH, Nuernberg, Germany
#*****************************************************************************
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


MAK_NAME=usr_utl

MAK_LIBS=


MAK_INCL=$(MEN_INC_DIR)/men_typs.h    \
         $(MEN_INC_DIR)/usr_utl.h

MAK_OPTIM=$(OPT_1)

MAK_INP1=atox$(INP_SUFFIX)
MAK_INP2=bindump$(INP_SUFFIX)
MAK_INP3=memdump$(INP_SUFFIX)
MAK_INP4=tstopt$(INP_SUFFIX)
MAK_INP5=ident$(INP_SUFFIX)
MAK_INP6=permit$(INP_SUFFIX)
MAK_INP7=protect$(INP_SUFFIX)
MAK_INP8=log$(INP_SUFFIX)

MAK_INP=\
        $(MAK_INP1)\
        $(MAK_INP2)\
        $(MAK_INP3)\
        $(MAK_INP4)\
        $(MAK_INP5)\
        $(MAK_INP6)\
        $(MAK_INP7)\
        $(MAK_INP8)
