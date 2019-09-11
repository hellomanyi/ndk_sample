LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hello-ndk
#LOCAL_MODULE_FILENAME :=

LOCAL_SRC_FILES := src/hello-ndk.c \
					src/init_array.c

#LOCAL_C_INCLUDES := 

LOCAL_CFLAGS := -fvisibility=hidden

#LOCAL_STATIC_LIBRARIES :=
#LOCAL_SHARED_LIBRARIES :=
LOCAL_LDLIBS := -ldl
#LOCAL_LDFLAGS :=
#LOCAL_ARM_MODE :=

include $(BUILD_SHARED_LIBRARY)
