# R-Tree

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-r-tree/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-r-tree/actions/workflows/cmake.yml)

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
5. Свободное дисковое пространство объемом ~ 4 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

#### Сборка проекта для Windows

_Опишите процесс сборки проекта._

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Algorithms-and-Data-Structures-2021/semester-work-r-tree
```

#### Генерация тестовых данных

Данные генерирует скрипт, написанный на языке Python (dataset/generate_csv_dataset.py). Он генерирует число в диапазоне от 0 до 100, используя функцию randit() из библиотеки random. Запускается через командную строку, принимает следующие аргументы: путь к файлу, куда следует сохранить результат, и количество данных. Скрипт написан с использованием библиотеки argparse. Сохраняет данные в формате .csv. 

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):
Для того, чтобы сгенерировать тестовые данные необходимо перейти в терминал и следовать инструкциям, которые указаны ниже.
```shell
Запуск скрипта для всех данных:
python generate_csv_dataset_all.py data/<название метода>/<название папки>

Запуск скрипта для данных:
python generate_csv_dataset.py data/<название метода>/<название папки> —samples=<кол-во данных>
```
В случае, если у вас не получается сгенерировать тестовые данные, можете перейти по ссылке на [Google Drive](https://drive.google.com/drive/folders/1ddeC8PrXWq_y_pHifsi7SI74G1HFJOz6), скачать папку dataset и заменить ее в самом проекте.
#### Контрольные тесты (benchmarks)

Для тестирования необходимо было создать три бенчмарка: для вставки, поиска, и удаления элемента. Бенчмарки используют сгенерированные файлы и считают за какое время в наносекундах  происходит операция, после чего заносят результаты в отдельный файл .csv. Полученные результаты используются для вычисления среднего значения времени, а также построения графиков.



##### Список контрольных тестов

| Название             | Описание         | Метрики |
| :---                 |   ---:           |  ---:   |
| `benchmark_insert`   | вставка объекта  | время   |
| `benchmark_search`   | поиск по области | время   |
| `benchmark_delete`   | удаление объекта | время   |

##### Инструкция по запуску контрольных тестов:

| Номер шага             | Папки и файлы         |
| :---                 |   ---:           |
| 1) Перейдите в папку с контрольными тестами.   | `benchmark`  |
| 2) В папке есть 3 файла с контрольными тестами, по названию понятно, какой метод они тестируют. Откройте один из них.|`benchmark_delete.cpp`  `benchmark_insert.cpp`  `benchmark_search.cpp`|
| 3) Запустите метод   | `main()` |
|4) В папке result есть 3 файла с метриками. После прогона одного из контрольных тестов, файл, который привязан к определенному бенчмарку, отобразит результаты тестирования.|`benchmark_delete_result.csv`  `benchmark_insert_result.csv`  `benchmark_search_result.csv`|
## Источники

_Список использованных при реализации структуры данных источников._

1. [Всевозможные репозитории других людей](https://github.com/search?l=C%2B%2B&q=rtree&type=Repositories)
2. [Википедия на русском](https://ru.wikipedia.org/wiki/R-дерево_(структура_данных))
3. [Википедия на английском](https://en.wikipedia.org/wiki/R-tree)
4. [Другая информация об R-tree](https://habr.com/ru/post/224965/)
