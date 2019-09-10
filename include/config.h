#ifndef _HELLO_NDK_CONFIG_
#define _HELLO_NDK_CONFIG_

#define EXPORT_INTERFACES __attribute__((visibility("default")))
#define INITARRS_INTERFACES __attribute__((section(".init_array")))

#endif
