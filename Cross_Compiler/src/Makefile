PATH=/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/deploy/sdk/Proyecto3/Gstreamer/sysroots/x86_64-pokysdk-linux/usr/bin:/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/deploy/sdk/Proyecto3/Gstreamer/sysroots/x86_64-pokysdk-linux/usr/bin/armv7a-vfp-neon-poky-linux-gnueabi:$PATH

PROG=Prograf
EJEC=Programa

PROGRA= $(PROG).c

CC=arm-poky-linux-gnueabi-gcc  -march=armv7-a -mthumb-interwork -mfloat-abi=softfp -mfpu=neon --sysroot=/home/andres/Descargas/BeagleBoard/poky-dylan-9.0.3/build/tmp/deploy/sdk/Proyecto3/Gstreamer/sysroots/armv7a-vfp-neon-poky-linux-gnueabi

GBIN=../bin/

$(EJEC): $(PROGRA)
		$(CC) -o $(GBIN)$(EJEC) $(PROGRA) 

