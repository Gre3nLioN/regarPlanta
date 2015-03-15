# regarPlanta
Sistema de regado automatico con Arduino

#Requisitos:
Copiar carpetas TimeAlarms y Time a la carpeta Libraries dentro de la carpeta principal de Arduino.

#Funcionamiento:
PIN_WATER es nuestro rele al cual se le conectara la bomba de agua.
La bomba de agua se prendera dos veces por dia, debido a las siguientes funciones:
MorningAlarm y NightAlarm.

La libreria TimeAlarms nos brinda la posibilidad de crear alarmas semanales, alarmas que suenen en fechas especificas, o alarmas que suenen todos los días.

#EXTRA:
El codigo tambien posee la integración de un buzzer para facilitar el testeado del mismo.
