#AGREGAR RECIPES A IMAGEN 

Primero descargar y descomprimir los paquetes necesarios de la imagen.

Crear carpeta meta-BIBLIOTECA en principal del sistema

Ingresar a la carpeta anterior y crear 2 carpetas : 

	-conf
	-recipes-BIBLIOTECA

Ingresar a carpeta conf y crear documento "layer.conf"

Modificar layer.conf y poner:

	# We have a conf and classes directory, add to BBPATH
	BBPATH := "${BBPATH}:${LAYERDIR}"
	# We have a packages directory, add to BBFILES
	BBFILES := "${BBFILES} ${LAYERDIR}/recipes-*/*/*.bb \
	${LAYERDIR}/recipes-*/*/*.bbappend"
	BBFILE_COLLECTIONS += "BIBLIOTECA"
	BBFILE_PATTERN_gstreamer := "^${LAYERDIR}/"
	BBFILE_PRIORITY_gstreamer := "5"

Ahora, ingresar a carpeta recipes-BIBLIOTECA que es donde van las recetas

Ingresar al link https://github.com/openembedded/openembedded-core
donde están las bibliotecas libres que podremos usar en el SE y descargarlas

Dentro de la carpeta descargada buscamos nuestra nueva BIBLIOTECA en "meta", "recipes-multimedia" y "BIBLIOTECA" copiamos y pegamos esta última en recipes-BIBLIOTECA anteriormente creada

Nuevamente en la carpeta descargada, buscamos en "meta", "recipes-devtools", "orc" copiamos y pegamos esta última en recipes-BIBLIOTECA anteriormente creada

Abrir la terminal y direccionarse en la carpeta principal del sistema de la imagen, misma donde creamos la carpeta meta-BIBLIOTECA

Establecer el ambiente con: $source oe-init-build-env

Luego: $hob

Con ese último comando se abrirá una ventana (HOB) donde se agregarán los nuevos layers ubicado la carpeta meta-BIBLIOTECA, de esa manera agregamos los nuevos layers

Igualmente en HOB seleccionamos nuestra "machine" y esperamos un momento. Luego aparecerá la opción para seleccionar la image y seleccionamos "create your own image" y clic en "edit image".

Ahora el HOB nos hubicará en edid recipes donde en la barra de busqueda ubicamos los recipes necesarios de la BIBLIOTECA e incluimos todos los paquetes, luego "build packages" y esperamos mientras se construyen los paquetes.

Luego, en edit packages y seleccionamos todo lo necesario nuevamente buscando desde la barra de busqueda y le damos "build image"

Y listo.




















