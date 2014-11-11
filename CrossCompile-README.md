#Secuencia para realizar la compilación cruzada una vez creada la imagen.

Para realizar la compilación cruzada primeramente se establece el ambiente en nuestra carpeta principal del archivo de la imagen.
Para establecer ingresamos el siguiente comando:

``` sh
$ source oe-init-build-env
```

Seguidamente:

``` sh
$ bitbake meta-toolchain-sdk
```
Luego nos posicionamos en la carpeta sdk donde ejecutaremos el toolchain:
	Ejm: ./poky-... .sh
	Se ingresa la dirección en la cual queremos que se generen los archivos y le damos que sí

Finalmente, dentro de la carpeta creada se encuentra un archivo environment por lo que ubicados ahi ingresamos:

``` sh
$ source environment...
```

Este último modifica nuestro environment para la compilación cruzada.
Lo abrimos y modificamos los macros del makefile de nuestra aplicación con los generados para la compilación cruzada.

Por último hacemos make a nuestro makefile.



