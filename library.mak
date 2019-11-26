#***************************  M a k e f i l e  *******************************
#
#         Author: see
#
#    Description: Makefile descriptor file for USR_UTL lib
#
#-----------------------------------------------------------------------------
#   Copyright 1998-2019, MEN Mikro Elektronik GmbH
#*****************************************************************************
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General License
# along with this program. If not, see <http://www.gnu.org/licenses/>.


MAK_NAME=usr_utl
# the next line is updated during the MDIS installation
STAMPED_REVISION="mdis_libsrc_usr_utl_com_01_42-5-g5063d1b-dirty_2019-05-28"

DEF_REVISION=MAK_REVISION=$(STAMPED_REVISION)
MAK_SWITCH=$(SW_PREFIX)$(DEF_REVISION)

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
