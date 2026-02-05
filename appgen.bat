@echo off
setlocal enabledelayedexpansion

rem Comprobar cantidad de argumentos
set counter=0
for %%A in (%*) do (
    set /A counter+=1
)

rem Si no hay exactamente 1 argumento, mostrar uso y salir
if %counter% neq 1 (
    echo [31mError: [0mse requiere exactamente un argumento: el nombre de la nueva aplicacion.
    echo Uso: appgen.bat [33m^<NombreApp^>[0m
    echo.
    echo Creara una nueva aplicacion basada en la plantilla 'Template'.
    echo El nuevo directorio de la aplicacion se crea en 'apps\^<NombreApp^>'.
    endlocal
    exit /b 1
)

rem Comprobar que el directorio Template existe
if not exist "Template" (
    echo [31mError: [0mno se encontro el directorio 'Template' en la ubicacion del script.
    echo Asegurese de ejecutar este script desde el directorio raiz del proyecto, donde se encuentra 'Template\'.
    endlocal
    exit /b 1
)

rem Comprobar que no exista ya una aplicacion con el mismo nombre
if exist "apps\%1" (
    echo [31mError: [0mya existe una aplicacion con el nombre '%1' en 'apps\%1'.
    echo Elija un nombre diferente o elimine el directorio existente.
    endlocal
    exit /b 1
)

rem Copiar plantilla a nuevo directorio
cp -r Template apps\%1

rem Reemplazar textos en los archivos de la nueva app
powershell -Command "(Get-Content apps\%1\Makefile) -replace 'APP_NAME = Template','APP_NAME = %1' | Set-Content apps\%1\Makefile"
powershell -Command "(Get-Content apps\%1\README.md) -replace 'Template','%1' | Set-Content apps\%1\README.md"

rem Cambiar al nuevo directorio de la aplicacion
cd /d "%~dp0apps\%1"
echo [32mAplicacion '%1' creada exitosamente a partir de la plantilla 'Template'.[0m

powershell