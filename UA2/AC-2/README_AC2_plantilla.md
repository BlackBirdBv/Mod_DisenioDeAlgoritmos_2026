# AC2 · Mi primera aplicación en C

**Estudiante:** (Kevin Moises Cardenas Blandon)  
**Fecha:** 20/10/2026  
**Módulo:** CSTI12010 Diseño de algoritmos · UA2

## Problema 1 · Nómina (AC2_P1_Nomina.c)

| Datos de entrada | Proceso                                                                               | Datos de salida | Limitaciones |
|------------------|---------------------------------------------------------------------------------------|-----------------|--------------|
| nombre, salario  | recibe el nombre y el salario, calcula los descuentos con validaciones para ver si aplican y muestra comprobante son la informacion del proceso y los cargos al salario  | nombre, comprobante, salario bruto, descuentos, salario neto | nombre no puede estar vacio, salario no puede ser 0 o negativo |

**Ejecución con los datos del ejemplo:**

![Ejecución](/UA2/AC-2/capturas/AC2_P1.png)

## Problema 2 · Calificaciones (AC2_P2_Calificaciones.c)

| Datos de entrada        | Proceso | Datos de salida | Limitaciones |
|-------------------------|---------|-----------------|--------------|
| nombre, calificaciones  | recibe el nombre y las notas(valida que esten en rango), se calcula el promedio se guarda la calificacion mas alta, se le asigna una condicion dependiendo del promedio y se muestra un resumen de la situacion del estudiante | pormedio, condicion, tres calificaciones ingresadas, nota mayor | las notas deben de estar en un rango de 0 a 100 |

**Ejecución con los datos del ejemplo:**

![Ejecución](/UA2/AC-2/capturas/AC2_P2.png)

## Problema 3 · Compras (AC2_P3_Compras.c)

| Datos de entrada | Proceso | Datos de salida | Limitaciones |
|------------------|---------|-----------------|--------------|
| Nombre cliente, producto, precio y camtidad, Opcion de continuar  | recibe el nombre del cliente, luego recibe el producto con su nombre su precio individual y su cantidad hasta un maximo de 10 o hasta que ya no quiera agragar mas, se validad que cantidad y prescio sean positivos, se realizan calculos como subtotal(precio x cantidad), descuento e imuestos para al final saber cuanto debe al final se muestra un resumen de compra | Factura con un resumen de lo que pidio el cliente, cantidades, precios, descuentos y total a pagar | el nombre no puede estar vacio, precio y cantidad no puede ser 0 o menor, el nombre del producto no puede quedar vacio, solo un maximo de 10 productos  |

**Ejecución con los datos del ejemplo:**

![Ejecución](captura_p.png)

## Conclusión

(Qué aprendí y qué fue lo más difícil de pasar de PSeInt a C.)
