== CORRECCIONES == 
1. En el create_thread: quitar contador de pilas assigadas. Por cada create_thread, 
   se hace busqueda lineal para encontrar pagina. Puede haber agujeros en memoria que 
   se usaran para otros threads (el heap serÃ¡CONSECUTIVO, las pilas asignadas a threads no). 

2. ÂComo sabemos que se aplica un exit thread al proceso y, en consecuencia, 
   no se libera memoria de manera erronea? [DOS PROCESOS Y EXIT AL PROCESOÂ?].

   Tenemos que: 
   - Nuevo atributo pag_assig en pcb con la pagina asignada al thread para 
      saber en el exit_thread que pagina debo liberar.
   - Nuevo atributo creat_threads en pcb que dice los threads creados (-1 si no tiene)
   - List con todos los threads creados, si tiene.


== ANOTACIONES ==
1. 
| heap | [hacia abajo]
|      | 
|      |
|      |
|      |
|Tstack| [hacia arriba]

La pila de los Threads puede "comerse" el espacio de memoria que podrÃ­a ser asignada a heap

2. 
