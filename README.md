# miditambor

Prototito interfaz midi-tambor-luminico.

Son 4 tambores, cada uno estará conectado a un arduino  el cual tiene que enviar una replica de la interpretacion en el tambor como señal MIDI a un mixer MIDI que se conecte al  computador  para interpretar sonidos sampleados o synths virtuales.

 1 tambora de dos parches con un piezo en cada parche y 4 pads con piezos en la parte superior conectados a un arduino  el cual tiene que enviar la señal MIDI de todos los triggers a un mixer MIDI que se conecte al  computador para interpretar sonidos sampleados o synths virtuales.
 
requerimientos:

Enviar mediante un piezo electrico (adosado a la membrana del tambor) la señal MIDI [note ON] y valor de Velocity

El mismo arduino al cual se conecta el piezo tiene que recibir la señal de un potenciometro en un pedal y definir asi el valor de la nota que toca el piezo.  Usando el pedal podremos cambiar el valor de la nota de manera cromatica dentro de un rango pre establecido a 2 o 3 octavas dependiendo de cada tambor.

(El arduino debe recibir la señal serial o (analoga) del piezo y el arduino-pedal para unirla en un solo fujo de informacion MIDI por salida fisica) 

Dentro del mismo pedal estará el arduino y una conexion de midi out en formato xlr para seguridad en escenario. El arduino alimentado por baterias.

Requerimientos complementarios:
-Mediante un segundo pedal poder modificar la duración (sustain) de la nota.

2 piezos o botones adicionales en los lados del tambor que puedan serivir como  swtiches para modificar por ejemplo el rango del pedal de nota o que sirvan como  triggers adicionales sin modificacion de la nota pero con sensibilidad  de velocity.

LUZ
unA malla de leds es activada por el sonido y genera patrones especificos en cada escena (cancion)
