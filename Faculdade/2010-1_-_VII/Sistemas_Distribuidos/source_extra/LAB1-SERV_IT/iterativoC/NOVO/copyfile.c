/* filecopy.c */
#include <stdio.h>

main() {
	char in_name[25], out_name[25];
	FILE *in_file, *out_file, *fopen ();
	int c;

	printf("File to be copied:\n");
	scanf("%24s", in_name);
	printf("Output filename:\n");
	scanf("%24s", out_name);

	in_file = fopen ( in_name, "r"); // r = read

	if( in_file == NULL )
		printf("Cannot open %s for reading.\n", in_name);
	else {
		out_file = fopen (out_name, "w"); //w = write
		if( out_file == NULL )
			printf("Can't open %s for writing.\n",out_name);
		else {
			while( !feof(in_file) ) {
				c = getc( in_file);
				putc (c, out_file);
			}
			printf("File has been copied.\n");
			fclose (out_file);
		}
		fclose (in_file);
	}
}
