# trabajo-final

## Subir commits a GitHub desde Visual Studio Code

##### Para subir commits a GitHub desde Visual Studio Code, sigue estos pasos:
- Abre el proyecto que quieres subir a GitHub.
- Haz los cambios que quieras en el proyecto.
- Guarda los cambios.
- En la barra lateral de Visual Studio Code, ve a Source Control (Ctrl + Shift + G), presionas el signo mas al lado de la palabra "Changes" o "Cambios".
- En el cuadro de diálogo Commit changes, escribe un mensaje que describa los cambios que has realizado.
- Haz clic en Commit.

##### Una vez que hayas realizado un commit, puedes subirlo a GitHub. Para ello, sigue estos pasos:
- En la barra lateral de Visual Studio Code, ve a Git > Push.
- En el cuadro de diálogo Push changes, selecciona el repositorio al que quieres subir los cambios.
- Haz clic en Push.

## Convenciones para los nombres de variables, funciones y estructuras

Las convenciones para los nombres de variables, funciones y estructuras ayudan a que el código sea más legible y mantenible.

##### Reglas para los nombres de clases:

- El nombre de la clase debe ser un sustantivo.
- Usa letras mayúsculas como separadores de palabras, minúsculas para el resto de la palabra en el nombre de la clase.
- El primer carácter del nombre de la clase debe estar en mayúsculas.
- No se permiten guiones bajos (‘\_’) en el nombre de la clase.

##### Reglas para los nombres de atributos privados

- El nombre del atributo privado en la clase debe ir precedido del carácter ‘m’.
- Después de anteponer ‘m’, se seguirán las mismas reglas para el nombre que para el nombre de la clase.
- El carácter ‘m’ también precede a otros modificadores de nombre. Por ejemplo, ‘p’ para punteros.
- Reglas para los nombres de métodos y funciones
- Cada nombre de método/función debe comenzar con un verbo.
- El primer carácter de los nombres de argumentos de funciones/métodos debe estar en minúsculas.
- Todas las palabras que comienzan después de la primera letra deben estar en mayúsculas con los nombres de las clases.

##### Reglas para los nombres de variables

- El nombre de la variable debe comenzar con un alfabeto.
- Se pueden usar dígitos en el nombre de la variable, pero solo después del alfabeto.
- No se pueden usar símbolos especiales en los nombres de las variables, excepto el guión bajo (‘\_’).
- No se pueden utilizar palabras clave para nombres de variables.
- Reglas para los nombres de variables de puntero, referencia y estática
- Las variables de puntero deben anteponerse con ‘p’ y colocar el asterisco ‘\*’ cerca del nombre de la variable en lugar del tipo de puntero.
- Las variables de referencia deben ir precedidas de ‘r’. Esto ayuda a diferenciar entre el método que devuelve un objeto modificable y el mismo método que devuelve un objeto no modificable.
- Las variables estáticas deben ir precedidas de ‘s’.

##### Reglas para los nombres de constantes globales

- Las constantes globales deben estar todas en mayúsculas separadas por (‘\_’).

##### Reglas para los nombres de archivos

- No se permite ningún carácter especial en el nombre del archivo excepto el guión bajo (‘\_’) y el guión (‘-‘).
- El nombre del archivo debe terminar con la extensión .cc al final o debe terminar con la extensión .cpp.
- No utilice nombres de archivo que ya existan en /user/include. o cualquier nombre de archivo de encabezado predefinido.

## Ejemplos

Clase: `Persona`

Atributo privado: `m_nombre`

Método: `calcular_edad()`

Variable: `edad`

Variable de puntero: `p_persona`

Variable de referencia: `r_persona`

Variable estática: `s_contador`

Constante global: `PI`

Archivo: `persona.cc`
