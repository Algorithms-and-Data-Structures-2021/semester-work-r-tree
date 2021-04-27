R-Tree

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-r-tree/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-r-tree/actions/workflows/cmake.yml)

Ссылка на [Google Drive](https://drive.google.com/drive/folders/1ddeC8PrXWq_y_pHifsi7SI74G1HFJOz6) с набором данных.

_Краткое описание семестрового проекта._

- _Реализуется структура R-tree._
- _R-дерево - древовидная структура данных, используется для организации доступа к пространственным данным, то есть для индексации многомерной информации._
- _R-дерево часто используется для хранения пространственных объектов, таких как местоположения ресторанов или многоугольников, из которых состоят типичные карты: улицы, здания, очертания озер, береговые линии R-дерево._
- _Над ней можно использовать операции такие как: поиск элементов на области, удаление элемента, вставка элемента._
- _Теоретическая сложность операций: поиск O(log m(n)), удаление O(log m(n)), вставка O(log n), т - минимальное количество потомков, n - общее количество узлов._

## Команда softBoys

| Фамилия Имя          | Вклад (%)    | Прозвище               |
| :---                 |   ---:       |  ---:                  |
| Герасимов Данил      | 33.3         |  _босс_                |
| Багаутдинов Даниил   | 33.3         |  _визуальный директор_ |
| Калугин Артем        | 33.3         |  _самозванец_          |

**Девиз команды**
> Ничего не понимаю! Ладно, притворюсь, что понял...

## Структура проекта

Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 16 ГБ.
5. Свободное дисковое пространство объемом ~ 10 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

#### Сборка проекта для Windows

_Опишите процесс сборки проекта._

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-r-tree
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-r-tree

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

Данные генерирует скрипт, написанный на языке Python (dataset/generate_csv_dataset.py). Он генерирует число в диапазоне от 0 до 100, используя функцию randit() из библиотеки random. Запускается через командную строку, принимает следующие аргументы: путь к файлу, куда следует сохранить результат, и количество данных. Скрипт написан с использованием библиотеки argparse. Сохраняет данные в формате .csv. 

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generate_csv_dataset.py data/insert/<название папки>
```

#### Контрольные тесты (benchmarks)

Для тестирования необходимо было создать три бенчмарка: для вставки, поиска, и удаления элемента. Бенчмарки используют сгенерированные файлы и считают за какое время в наносекундах  происходит операция, после чего заносят результаты в отдельный файл .csv. Полученные результаты используются для вычисления среднего значения времени, а также построения графиков.

Набор входных данных содержится в репозитории, поэтому для скачивания проекта может потребоваться время.

##### Список контрольных тестов

| Название             | Описание         | Метрики |
| :---                 |   ---:           |  ---:   |
| `benchmark_insert`   | вставка объекта  | время   |
| `benchmark_search`   | поиск по области | время   |
| `benchmark_delete`   | удаление объекта | время   |

## Источники

_Список использованных при реализации структуры данных источников._

https://github.com/search?l=C%2B%2B&q=rtree&type=Repositories
https://ru.wikipedia.org/wiki/R-дерево_(структура_данных)
https://en.wikipedia.org/wiki/R-tree
https://habr.com/ru/post/224965/
