# Aplicación STM32F446RE — 8_ADC

## Descripción

Descripción de ejemplo de la aplicación:
Aplicación base que implementa un Blink simple sobre el microcontrolador STM32F446RE.
(Modificar según la aplicación desarrollada).

---

## Plataforma

- STM32F446RE
- ARM Cortex-M4
- Desarrollo bare-metal
- Toolchain arm-none-eabi local al proyecto
- OpenOCD + ST-Link

---

## Estructura de la carpeta

```text
8_ADC/
├── Makefile            # Reglas de compilación
├── make.bat            # Wrapper para Windows
├── Inc/                # Headers específicos de la app
│   └── *.h
├── Src/                # Código fuente
│   ├── main.c
│   └── *.c
├── build/              # Archivos intermedios (.o, .d)
├── bin/                # Salida final (ELF, BIN, MAP)
└── README.md           # Documentación de esta app
```

## Operaciones básicas

- Compilar:
  - `./make.bat build`
  - `./make.bat`

- Limpiar:
  - `./make.bat clean`

- Flashear:
  - `./make.bat flash`

- Compilar y flashear:
  - `./make.bat all`

---

## Funcionamiento

Funcionamiento de ejemplo de la aplicación:
Inicializa el sistema y conmuta periódicamente el estado del GPIO configurado como salida,
produciendo el parpadeo del LED.
(Modificar según la aplicación desarrollada).

---

## Archivos generados

- ELF (.elf)
- Archivos intermedios Objects(.o)
