/*
 * This program is free software;  you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY;  without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 * the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program;  if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/utsname.h>

int main(void)
{
	struct utsname kname;

	if (uname(&kname)) {
		fprintf(stderr, "get uname failed: %s\n", strerror(errno));
		exit(-1);
	}

	printf("System is %s on %s hardware:\n", kname.sysname, kname.machine);

	/* print size for C data types */
	printf("sizeof (char)		= %2luB,\n", sizeof(char));
	printf("sizeof (short)		= %2luB,\n", sizeof(short));
	printf("sizeof (int)		= %2luB,\n", sizeof(int));
	printf("sizeof (long)		= %2luB,\n", sizeof(long));
	printf("sizeof (long long)	= %2luB,\n", sizeof(long long));

	printf("sizeof (float)		= %2luB,\n", sizeof(float));
	printf("sizeof (double)		= %2luB,\n", sizeof(double));
	printf("sizeof (long double)	= %2luB.\n", sizeof(long double));

	return 0;
}
