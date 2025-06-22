# Gestor de Alumnos

## Descripción del proyecto

**Gestor de Alumnos** es una aplicación de consola escrita en C que permite gestionar la información de estudiantes. El programa permite cargar alumnos, registrar sus notas, buscar alumnos por nombre o DNI, mostrar los mejores promedios y guardar/cargar la información en un archivo binario para su persistencia.

## Integrantes y roles

- **Luciano**: Desarrollador principal (DEV)

## Instrucciones para compilar y ejecutar

### En Windows

1. **Instalar MinGW** (si no tienes un compilador C):
   - Descarga e instala MinGW desde [https://osdn.net/projects/mingw/](https://osdn.net/projects/mingw/).
   - Asegúrate de agregar `mingw/bin` a la variable de entorno `PATH`.

2. **Abrir la terminal de comandos** (cmd) y navegar a la carpeta del proyecto.

3. **Compilar el programa**:
   ```sh
   gcc main.c -o gestorAlumnos.exe
   ```

4. **Ejecutar el programa**:
   ```sh
   gestorAlumnos.exe
   ```

---

### En Linux

1. **Abrir la terminal** y navegar a la carpeta del proyecto.

2. **Instalar GCC** (si no lo tienes):
   ```sh
   sudo apt update
   sudo apt install build-essential
   ```

3. **Compilar el programa**:
   ```sh
   gcc main.c -o gestorAlumnos
   ```

4. **Ejecutar el programa**:
   ```sh
   ./gestorAlumnos
   ```

---

## Notas

- El programa guarda los datos en un archivo binario llamado `alumnos.dat` en la misma carpeta.
- El menú es interactivo y permite realizar todas las operaciones desde la consola.

---
```// filepath: /home/luciano/personalProject/gestorAlunmo/README.md
# Gestor de Alumnos

## Descripción del proyecto

**Gestor de Alumnos** es una aplicación de consola escrita en C que permite gestionar la información de estudiantes. El programa permite cargar alumnos, registrar sus notas, buscar alumnos por nombre o DNI, mostrar los mejores promedios y guardar/cargar la información en un archivo binario para su persistencia.

## Integrantes y roles

- **Luciano**: Desarrollador principal (DEV)

## Instrucciones para compilar y ejecutar

### En Windows

1. **Instalar MinGW** (si no tienes un compilador C):
   - Descarga e instala MinGW desde [https://osdn.net/projects/mingw/](https://osdn.net/projects/mingw/).
   - Asegúrate de agregar `mingw/bin` a la variable de entorno `PATH`.

2. **Abrir la terminal de comandos** (cmd) y navegar a la carpeta del proyecto.

3. **Compilar el programa**:
   ```sh
   gcc main.c -o gestorAlumnos.exe
   ```

4. **Ejecutar el programa**:
   ```sh
   gestorAlumnos.exe
   ```

---

### En Linux

1. **Abrir la terminal** y navegar a la carpeta del proyecto.

2. **Instalar GCC** (si no lo tienes):
   ```sh
   sudo apt update
   sudo apt install build-essential
   ```

3. **Compilar el programa**:
   ```sh
   gcc main.c -o gestorAlumnos
   ```

4. **Ejecutar el programa**:
   ```sh
   ./gestorAlumnos
   ```

---

## Notas

- El programa guarda los datos en un archivo binario llamado `alumnos.dat` en la misma carpeta.
- El menú es interactivo y permite realizar todas las operaciones desde la consola.

---