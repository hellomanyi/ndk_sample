#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "include/config.h"

typedef int (* hello_ndk_sym)(void);

extern void init_array_2(void);
extern void init_array_3(void);


static void init_array_1(void) {
	/* try to get total symbols tables */
	void* symbols = dlopen(NULL, RTLD_NOW);

	if (dlerror() != NULL) {
		goto failed;
	}

	hello_ndk_sym visible_ndk = dlsym(symbols, "hello_ndk_visible");
	if (dlerror() != NULL) {
		goto failed;
	}

	visible_ndk();

	dlclose(symbols);

failed:
	return;
}

static void ndk_init_array(void) {
	init_array_1();
	init_array_2();
	init_array_3();
}

INITARRS_INTERFACES
typeof(ndk_init_array) *__ndk_init_array = ndk_init_array;


EXPORT_INTERFACES
int hello_ndk_visible(void) {
	printf("hello ndk visible\n");
	return 0;
}

int hello_ndk_hidden(void) {
	printf("hello ndk hidden\n");
	return 0;
}
