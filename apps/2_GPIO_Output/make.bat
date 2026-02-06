@echo off
rem make.bat - versión mejorada: acepta targets y opciones

setlocal enabledelayedexpansion

rem Directorio del script
set "SCRIPT_DIR=%~dp0"

rem Ruta por defecto al ejecutable make (relativa al script)
set "DEFAULT_MAKE=%SCRIPT_DIR%..\..\toolchain\make\make.exe"

rem Permitir sobrescribir la ruta con la variable de entorno MAKE_EXE
if defined MAKE_EXE (
	set "MAKE_PATH=%MAKE_EXE%"
) else (
	set "MAKE_PATH=%DEFAULT_MAKE%"
)

rem Inicializar variables
set "DRY=0"
set "SHOW_HELP=0"
set "VERBOSE=0"
set "MAKE_ARGS="

rem Analizar argumentos: soporta --dry-run (-n), --help y --verbose; el resto se pasa a make como targets/flags
for %%A in (%*) do (
	if /I "%%~A"=="--dry-run" (set "DRY=1") else if /I "%%~A"=="-n" (set "DRY=1") else if /I "%%~A"=="--help" (set "SHOW_HELP=1") else if /I "%%~A"=="--verbose" (set "VERBOSE=1") else if /I "%%~A"=="--debug" (set "VERBOSE=1") else (
		if defined MAKE_ARGS (
			set "MAKE_ARGS=!MAKE_ARGS! %%~A"
		) else (
			set "MAKE_ARGS=%%~A"
		)
	)
)

rem Si no se pasan argumentos (aparte de opciones), usar 'build' por defecto
if not defined MAKE_ARGS set "MAKE_ARGS=build"

rem Comprobar existencia del ejecutable
if not exist "%MAKE_PATH%" (
	echo Error: no se encontro el ejecutable de make en:
	echo    %MAKE_PATH%
	echo Establezca la variable de entorno MAKE_EXE con la ruta al ejecutable, o coloque make en ..\..\toolchain\make\
	endlocal
	exit /b 1
)

rem Si se solicita verbose, mostrar variables internas para depuracion
if "%VERBOSE%"=="1" (
	echo [verbose] SCRIPT_DIR=%SCRIPT_DIR%
	echo [verbose] MAKE_PATH=%MAKE_PATH%
	echo [verbose] MAKE_ARGS=!MAKE_ARGS!
)

pushd "%SCRIPT_DIR%" >nul
if "%DRY%"=="1" (
	echo [dry-run] Comando que se ejecutaria: "%MAKE_PATH%" !MAKE_ARGS!
	popd >nul
	endlocal
	exit /b 0
)

echo Ejecutando: "%MAKE_PATH%" !MAKE_ARGS!
"%MAKE_PATH%" !MAKE_ARGS!
set "RC=%ERRORLEVEL%"
popd >nul

endlocal
exit /b %RC%