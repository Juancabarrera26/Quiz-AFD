# Quiz — AFD para tokens `+`, `++` e `ID`

Este repositorio contiene la implementacion de un **AFD (Automata Finito Determinista)** que reconoce los tokens definidos por las siguientes expresiones regulares:

- `+`  → **SUMA**
- `++` → **INCR**
- `[A-Z][a-z0-9]*` → **ID**

La entrada se lee desde un archivo `.txt` y la salida se imprime por pantalla token por token.  
Si una cadena **no es aceptada**, debe imprimirse: **`NO ACEPTA`**.

---

## Tokens reconocidos

| Token | Expresion regular | Descripcion |
|------:|-------------------|-------------|
| SUMA  | `+`               | simbolo de suma |
| INCR  | `++`              | incremento |
| ID    | `[A-Z][a-z0-9]*`  | Identificador: empieza con mayuscula y continua con minusculas o digitos |

---

## Tabla de transicion del AFD (resumen)

Estados:
- `0`: estado inicial  
- `1`: se leyo `+`  
- `2`: se leyo `++` (aceptacion **INCR**, pero no permite mas caracteres)  
- `3`: se leyo una letra mayuscula (aceptacion **ID**, permite `[a-z0-9]*`)  

Transiciones principales:
- Desde `0` con `+` → `1`
- Desde `1` con `+` → `2`
- Desde `0` con `[A-Z]` → `3`
- Desde `3` con `[a-z0-9]` → `3`
- Cualquier otro caso → **rechazo**

Aceptación:
- Estado `1` → `SUMA`
- Estado `2` → `INCR`
- Estado `3` → `ID`

---

## Archivos del repositorio

- `afd.py` → implementacion en Python
- `afd.c` → implementacion en C
- `entrada.txt` → archivo de prueba con cadenas separadas por espacios o saltos de linea

Contenido usado para las pruebas (`entrada.txt`):

```txt
+
++
+++
Hola
A123
a123
```
# Ejecucion en Python

## Ejecutar

El programa recibe el archivo por argumento:

```
python afd.py entrada.txt
```
Salida esperada con entrada.txt

<img width="599" height="142" alt="Captura de pantalla 2026-02-24 194105" src="https://github.com/user-attachments/assets/e84988ac-2f60-43f2-837d-32f7c3396ff1" />

# Ejecucion en C

## Compilar

```
gcc afd.c -o afd
```

## Ejecutar

Este programa lee directamente el archivo entrada.txt (debe estar en el mismo directorio):

```
./afd
```

Salida esperada con entrada.txt

<img width="599" height="171" alt="Captura de pantalla 2026-02-24 194943" src="https://github.com/user-attachments/assets/430d4330-db1a-4443-b775-8c687a86fc2e" />

# Notas importantes

+++ no es valido porque el AFD solo acepta + o ++. Despues de aceptar ++, cualquier caracter extra hace que rechace.

Hola es ID porque:

H es mayuscula 

ola son minusculas 

A123 es ID porque:

A mayuscula 

123 son dígitos 

a123 NO ACEPTA porque inicia con minuscula



