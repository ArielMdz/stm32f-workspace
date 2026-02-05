import sys
import shutil
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
TEMPLATE_DIR = BASE_DIR / "Template"
APPS_DIR = BASE_DIR / "apps"

# Mostrar uso correcto del script
def usage():
    print("Uso: python appgen.py <nombre_app>")
    sys.exit(1)

# Crear una nueva app a partir del template base
def create_app(app_name: str):
    dest = APPS_DIR / app_name

    if not TEMPLATE_DIR.exists():
        print("❌ No existe el template base")
        sys.exit(1)

    if dest.exists():
        print(f"❌ La app '{app_name}' ya existe")
        sys.exit(1)

    shutil.copytree(TEMPLATE_DIR, dest)
    print(f"✔ App '{app_name}' creada en: {dest}")

# Reemplazar texto en un archivo
def replace_text_in_file(file_path: Path, old: str, new: str):
    try:
        text = file_path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        # Evita archivos binarios
        return

    if old not in text:
        return

    text = text.replace(old, new)
    file_path.write_text(text, encoding="utf-8")

# Función principal
def main():
    # Validar cantidad de argumentos
    if len(sys.argv) != 2:
        usage()

    # Crear la app
    app_name = sys.argv[1]
    create_app(app_name)

    # Reemplazar textos en los archivos de la nueva app
    replace_text_in_file(APPS_DIR / app_name / "Makefile", "APP_NAME = Template", f"APP_NAME = {app_name}")

    replace_text_in_file(APPS_DIR / app_name / "README.md", "# Aplicación STM32F446RE — Template", f"# Aplicación STM32F446RE — {app_name}")

    replace_text_in_file(APPS_DIR / app_name / "README.md", "Template/", f"{app_name}/")

if __name__ == "__main__":
    main()
