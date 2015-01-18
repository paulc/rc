/*
   This file is NOT BUILT by default.  Together with addon.h, it
   provides an example of how to add new builtins to rc.
*/

#include "rc.h"
#include "addon.h"

void b_incr(char **av) {
    if (*++av == NULL) {
        rc_error("syntax error");
    }
    char *name = *av;
    long incr = (*++av == NULL) ? 1 : atol(*av);
    List *l = varlookup(name);
    long v = ((l == NULL) ? 0 : atol(l->w)) + incr;
    List *r = nnew(List);
    r->w = nprint("%ld",v);
    r->m = NULL;
    r->n = NULL;
    varassign(name,r,FALSE);
	set(TRUE);
}

void b_gt(char **av) {
    long a = (*++av == NULL) ? 0 : atol(*av);
    long b = (*++av == NULL) ? 0 : atol(*av);
    if (b > a) {
        set(TRUE);
    } else {
        set(FALSE);
    }
}

void b_lt(char **av) {
    long a = (*++av == NULL) ? 0 : atol(*av);
    long b = (*++av == NULL) ? 0 : atol(*av);
    if (b < a) {
        set(TRUE);
    } else {
        set(FALSE);
    }
}

void b_eq(char **av) {
    long a = (*++av == NULL) ? 0 : atol(*av);
    long b = (*++av == NULL) ? 0 : atol(*av);
    if (b == a) {
        set(TRUE);
    } else {
        set(FALSE);
    }
}

void b_sum(char **av) {
	long sum = 0;

	while (*++av)
		sum += atol(*av);
	fprint(1, "%ld\n", sum);
	set(TRUE);
}

void b_prod(char **av) {
	long sum = 1;

	while (*++av)
		sum *= atol(*av);
	fprint(1, "%ld\n", sum);
	set(TRUE);
}
