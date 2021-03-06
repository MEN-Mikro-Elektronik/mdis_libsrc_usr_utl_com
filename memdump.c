/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *        \file  memdump.c
 *
 *      \author  see
 *
 *     \project  UTL library
 *  	 \brief  Print formatted hexdump
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
/** Print formatted hexdump
 *
 *  Trailing blanks in the description string define the
 *  indention of all following debug lines.
 *  \n
 *  E.g. output for
 * \code
 * UTL_Memdump("WORD access", (char*)0x0000f000, 0x40, 2);
 * \endcode
 * is:
 * \code
 *	WORD access (64 bytes):
 *	0000f000+0000: 4afc 0001 0000 007c 0000 0009 0000 0074 J|.....|.......t
 *	0000f000+0010: 0777 0f00 8000 0006 0000 0000 0000 0000 .w..............
 *	0000f000+0020: 0000 0000 0000 0000 0000 0000 0000 3d72 ..............=r
 *	0000f000+0030: 00ff ee00 5c04 0023 0064 0068 0070 0000 ..n.\..#.d.h.p..
 * \endcode
 *
 *  \param info    \IN description string or NULL (first line)
 *  \param buf     \IN memory start address
 *  \param n       \IN memory length [bytes]
 *  \param fmt     \IN output format\n
 *                     1 = byte aligned\n
 *                     2 = word aligned\n
 *                     4 = long aligned\n
 *                     8 = 64-bit aligned
 */
void __MAPILIB UTL_Memdump(
    char *info,
    char *buf,
    u_int32 n,
    u_int32 fmt
)
{
    char *k, *k0, *kmax = buf+n;
	char *s = info;
    int32 i, b, blanks=0;

    if (info) {
		while(*s++ == ' ')			/* count trailing blanks */
			blanks++;

		printf("%s (%ld bytes)\n",info,n);	/* print info */
	}

    for (k=k0=buf; k0<kmax; k0+=16)
    {
		for (b=0; b<blanks; b++)	/* write trailing blanks */
			printf(" ");

#ifndef MENTYPS_64BIT
		printf("%08x+%04x: ",(unsigned int) buf, (unsigned int)(k-buf));
#else
		printf("%016x+%04x: ",(U_INT32_OR_64) buf, (unsigned int)(k-buf));
#endif /* U_INT32_OR_64 is u_int32 */

		switch(fmt)                                        /* dump hex: */
        {
           case 8 : for (k=k0,i=0; i<16; i+=8, k+=8)       /* 64-bit aligned */
                       if (k<kmax)  printf("%08lx%08lx ",*(u_int32*)k,*(u_int32*)(k+4));
                       else         printf("         ");
                    break;
           case 4 : for (k=k0,i=0; i<16; i+=4, k+=4)       /* long aligned */
                       if (k<kmax)  printf("%08lx ",*(u_int32*)k);
                       else         printf("         ");
                    break;
           case 2 : for (k=k0,i=0; i<16; i+=2, k+=2)       /* word aligned */
                       if (k<kmax)  printf("%04x ",*(u_int16*)k & 0xffff);
                       else         printf("     ");
                    break;
           default: for (k=k0,i=0; i<16; i++, k++)         /* byte aligned */
                       if (k<kmax)  printf("%02x ",*k & 0xff);
                       else         printf("   ");
        }

        for (k=k0,i=0; i<16 && k<kmax; i++, k++)                /* dump ascii */
            if ( *(u_int8*)k>=32 && *(u_int8*)k<=127 )
               printf("%c", *k);
            else
               printf(".");

        printf("\n");
    }
}
