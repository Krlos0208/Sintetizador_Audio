# CREAR BOOTEABLE DE LA IMAGEN PARA SD

Primero formatear SD y realizar partición con GParted.

``` sh
sudo mkfs.vfat -F 16 -n "boot" /dev/mmcblk0p1
sudo mke2fs -j -L "root" /dev/mmcblk0p2
```

SON LOS NOMBRES DE LAS ETIQUETAS: boot y root

``` sh
sudo cp MLO-beagleboard /media/boot/MLO

sudo cp u-boot-beagleboard.bin /media/boot/u-boot.bin

sudo tar x -C /media/root -f core-image-sato-beagleboard.tar.bz2

sudo tar x -C /media/root -f modules-

sudo cp uImage-beagleboard.bin /media/boot/uImage

(cat << EOF
setenv bootcmd 'mmc init; fatload mmc 0:1 0x80300000 uImage; bootm 0x80300000'
setenv bootargs 'console=tty0 console=ttyO2,115200n8 root=/dev/sdb2 rootwait rootfstype=ext3 ro'
boot
EOF
) > serial-boot.cmd

sudo mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n "Core_SATO" -d ./serial-boot.cmd ./boot.scr
```
