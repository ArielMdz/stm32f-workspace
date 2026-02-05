# STM32F446RE – Bare-Metal App Framework

Este repositorio proporciona un **entorno autocontenido** para crear, compilar, cargar y depurar **aplicaciones bare-metal para el microcontrolador STM32F446RE**, utilizando **VSCode en Windows**.

El objetivo principal del proyecto es **simplificar y estandarizar** la creación de nuevas apps para STM32 sin necesidad de reinstalar toolchains, SDKs o dependencias externas en el sistema.

---

## Características principales

- Desarrollo **bare-metal** para STM32F446RE  
- Pensado para usarse en **Windows + VSCode**
- **No requiere instalar toolchains globales**
- Toolchains y utilidades **incluidas de forma local**
- Generación automática de apps mediante `appgen.bat`
- Estructura limpia y reutilizable para múltiples proyectos
- Cada app es **autosuficiente** y se trabaja de forma aislada

---

## Requisitos

Únicamente necesitas:

- Clonar este repositorio
- Tener terminal **PowerShell** instalado

No es necesario instalar:
- GCC ARM
- OpenOCD
- CMSIS
- SDKs adicionales

Todas las herramientas necesarias para compilar y cargar están incluidas de forma local dentro del repositorio.

---

## Estructura del proyecto

```text
STM32F446RE/
│
├── .vscode/            # Configuración de VSCode (global)
│
├── apps/               # Aplicaciones creadas por el usuario
│   └── Demo/           # Ejemplo de app generada
│       ├── Inc/        # Carpeta de headers
│       ├── Src/        # Carpeta de código fuente
│       │   └── main.c
│       ├── make.bat
│       ├── Makefile
│       └── README.md
│
├── CMSIS/              # CMSIS oficial (NO modificar)
├── Linker/             # Scripts de linker (NO modificar)
├── Startup/            # Código de arranque (NO modificar)
│
├── Template/           # Plantilla base para nuevas apps (NO modificar)
│   ├── Inc/
│   ├── Src/
│   ├── make.bat
│   ├── Makefile
│   └── README.md
│
├── toolchain/          # Toolchains y herramientas locales
│   ├── arm-none-eabi   # GCC ARM toolchain para compilación
│   ├── OpenOCD         # OpenOCD para programación y depuración
│   └── make            # Make utility
├── appgen.bat          # Generador de nuevas apps
└── README.md           # Este archivo
```

---

## Flujo de trabajo

1. Crear una nueva app usando `appgen.bat <NombreDeLaApp>`
2. La app se genera automáticamente dentro de la carpeta `apps/`
3. Todo el desarrollo, compilación y carga se realiza **desde la carpeta de la app**
4. Cada app es independiente del resto

---

## Uso de `appgen.bat`

El script `appgen.bat` se encarga de:

- Copiar la plantilla ubicada en `Template/`
- Renombrarla con el nombre proporcionado
- Guardar la nueva app dentro de la carpeta `apps/`
- Re-ubicara la terminal en la carpeta de la nueva app

### Ejemplo de uso

```bash
appgen.bat <MiNuevaApp>
```

Esto generará automáticamente:

```text
apps/MiNuevaApp/
```
con toda la estructura mínima necesaria para comenzar a trabajar.

---

## Compilación y carga

⚠ **Toda compilación, carga o depuración debe realizarse desde la carpeta de la app**, no desde la raíz del proyecto.

Ejemplo:

```text
apps/MiNuevaApp/
```

Desde ahí deben ejecutarse los comandos de compilación y carga usando el Makefile y scripts incluidos en la app.

---

### Reglas importantes

⚠ **NO modificar** bajo ninguna circunstancia:

- La carpeta `Template/`
- Las carpetas `CMSIS/`, `Startup/`, `Linker/`, `toolchain/`
- Archivos globales del proyecto

✔ **Únicamente debe modificarse**:

- El contenido de la app creada dentro de `apps/<TuApp>/`
- Sus carpetas `Inc/` y `Src/`
- Archivos propios de esa app

Modificar el template o las carpetas base puede romper:

- La generación de nuevas apps
- La compatibilidad entre proyectos
- El flujo de compilación

---

## Filosofía del proyecto

Este framework está diseñado para:

- Mantener **orden y consistencia** entre proyectos STM32
- Evitar instalaciones repetitivas de herramientas
- Facilitar la portabilidad del entorno
- Permitir crear múltiples apps sin duplicar configuraciones

Cada app es un proyecto autocontenido, pero todas comparten una base común controlada.
