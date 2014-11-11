GENCCODE_ASSEMBLY_TYPE=-a gcc
SO=so
SOBJ=so
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=.50.1.2
COMPILE=arm-poky-linux-gnueabi-gcc  -march=armv7-a -mthumb-interwork -mfloat-abi=softfp -mfpu=neon --sysroot=/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/sysroots/beagleboard -D_REENTRANT   -DU_ATTRIBUTE_DEPRECATED= -Os -Wall -std=c99 -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings  -c
LIBFLAGS=-I/usr/include -DPIC -fPIC
GENLIB=arm-poky-linux-gnueabi-gcc  -march=armv7-a -mthumb-interwork -mfloat-abi=softfp -mfpu=neon --sysroot=/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/sysroots/beagleboard -Os -Wall -std=c99 -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings  -Wl,-O1 -Wl,--hash-style=gnu  -shared -Wl,-Bsymbolic
LDICUDTFLAGS=-nodefaultlibs -nostdlib
LD_SONAME=-Wl,-soname -Wl,
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=arm-poky-linux-gnueabi-ar
ARFLAGS=r
RANLIB=arm-poky-linux-gnueabi-ranlib
INSTALL_CMD=/usr/bin/install -c
