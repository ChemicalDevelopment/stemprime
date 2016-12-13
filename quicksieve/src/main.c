/*

	ChemicalDevelopment 2016.

	QS (quicksieve) project is licensed under the GPLv2 with some exceptions. See LICENSE for more information.

	Simple calling interface

	2016-11-29:
	  Initial project, including simple eratosthenes implementation


*/

// standard libraries
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// getting input flags (custom implementation)
#include "input/input.h"

#include "bstypes.h"

#include "output/string_out.h"

#include "sieves/eratosthenes.h"
#include "sieves/bitlib.h"



int main(int argc, char *argv[]) {
	init_input(argc, argv);

	if (get_flag("-h")) {
		printf("QuickSieve by ChemicalDevelopment\n");
		printf("  -print : prints the primes in the sieve\n");
		printf("  -sieve [n] : sieves up to n\n");
		printf("  -count : prints the amount of primes less than [-sieve n]\n");
		return 0;
	}


	if (get_flag("-sieve")) {
		long int n = get_int_var("-sieve", 1000);
		bitset_t set;
		//bitset_erat(&set, n);
		bitset_erat(&set, n);
		
		if (get_flag("-count") || !get_flag("-print"))
			printf("%ld primes <= %ld\n", count(set, n), n);

		if (get_flag("-print")) {
			print_primes_base(set, n, get_int_var("-base", 10));
		}

	}

	return 0;
}




