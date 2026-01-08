# "Умный" телефонный справочник

## Фичи

- CLI интерфейс
- Добавление/удаление/изменение контактов
- Автоматическая сортировка контактов по имени
- Поиск контактов по имени/телефону/почте
- Сохранение/загрузка записей из файла

## Установка

### Windows
#### Требования:
- `MinGW-w64`
- `CMake`

#### Шаги:
1. Клонировать репозиторий:
    ```bash
    git clone https://github.com/bemn/phone-book
    cd phone-book
    ```
2. Собрать проект:
    ```bash
    cmake -G "MinGW Makefiles" .
    cmake --build .
    ```

### Linux/MacOS
#### Требования:
- `gcc` или `clang`
- `cmake`
- `make` или `ninja`

#### Шаги:
1. Клонировать репозиторий:
    ```bash
    git clone https://github.com/bemn/phone-book
    cd phone-book
    ```
2. Создать директорию для сборки:
    ```bash
    mkdir build
    cd build
    ```
3. Собрать проект:
    ```bash
    cmake ..
    cmake --build .
    ```

## Использование
**Windows:**
Запускать файл `phone-book.exe` в корне проекта.

**Linux/MacOS:**
Запускать файл `phone-book` внутри директории `build`.