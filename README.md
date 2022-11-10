# **25.4 Практическая работа**

#### Задача. 

Цели практической работы
Приобрести понимание разбиения проекта на исходные и заголовочные файлы.
Научиться использовать основные команды CMake.


Что входит в работу
Реализовать симулятор проведения операций.
Создать модульный проект симулятора работы компьютера.
Общие условия

Разработка выполняется в среде CLion.


## **Задание 1. Симулятор проведения операций**

Что нужно сделать
Реализуйте простой симулятор проведения медицинской операции у пациента. Пользователь выступает 
в роли хирурга, который запрашивает инструменты у ассистента и применяет их сообразно ситуации.

Пользователь взаимодействует с программой с помощью команд. Команды не имеют сложной встроенной логики:
они просто принимают нужные данные в качестве аргументов и выводят сообщения в консоль о выполнении. 
Данные команд — это одна или две двумерные точки в формате double с координатами X и Y соответственно.

### Команда scalpel — принимает на вход две двумерные координаты начала и конца разреза или линии отсечения. При выполнении в консоль выводится сообщение о том, что был сделан разрез между введёнными координатами.

### Команда hemostat принимает на вход одну точку, в которой требуется сделать зажим, о чём также сообщает в консоль.

### Команда tweezers — пинцет, как и зажим, принимает одну точку для применения. Сообщение об этом выводится в консоль.

### Команда suture — хирургическая игла, которая делает шов между двумя указанными точками.

Операция всегда начинается с команды scalpel и заканчивается командой suture. 
Для окончания работы программы их параметры-точки должны совпасть.

Программу требуется реализовать именно с помощью одного заголовочного файла и одного файла с исходным кодом (CPP).
В заголовочном файле должны находиться функции-инструменты. В основном файле — основная логика программы, обработка
ввода пользователя.

_Советы и рекомендации
Создайте структуру с типом двумерной координаты (точки) вместе с набором функций для ввода этой координаты из
консоли, её вывода в консоль и сравнения на предмет равенства. Для этих целей удобнее всего создать ещё один 
заголовочный файл. Обратите внимание на порядок команд. Заголовочные файлы с расширением .h следует расположить 
в папке include. Файлы исходного кода с расширением .cpp — в папке src._

Что оценивается
Все команды вводятся пользователем через стандартный ввод.
Программа и CMake-файл конфигурации проекта работают корректно.



## Задание 2. Проект симулятора работы компьютера

Что нужно сделать
Реализуйте простую модель работы персонального компьютера в качестве многомодульного проекта. В компьютере 
несколько основных, условных компонент.

### Центральный процессор (cpu) — должен иметь функцию compute, которая складывает 8 чисел из буфера оперативной памяти (см. далее) и выводит результат в консоль.

### Оперативная память (ram) — содержит буфер на 8 целых чисел, которые можно заполнить функцией write и считать функцией read.

### Жёсткий диск (disk) — имеет в себе две функции, save и load. Функция save должна сохранить состояние 8 чисел из оперативной памяти на постоянный носитель в файл data.txt. Функция load — загрузить их с носителя в оперативную память.

### Графическая карта (gpu) — выводит в консоль 8 чисел из оперативной памяти.

### Клавиатура (kbd) — позволяет ввести 8 чисел и разместить их в оперативной памяти.

Каждая компонента должна располагаться в отдельном модуле, с отдельным заголовочным файлом. Основной модуль
программы (main.cpp) должен считывать пользовательский ввод команды, которая соответствует отдельным функциям 
устройств:
sum (вычисление суммы), 
save (сохранить в файл), 
load (загрузить из файла), 
input (ввести с клавиатуры), 
isplay (вывести на экран). 
Команда exit — выходит из программы.

_Советы и рекомендации
Тщательно продумайте зависимости между модулями и теми файлами, которые должны быть включены в исходные файлы. Не забывайте про #pragma once в заголовочных файлах.
В заголовочных файлах модулей располагайте только объявления функций. Их определения должны быть уже в исходных файлах (CPP)._

**Что оценивается
Обращение к буферу оперативной памяти делается только через модуль ram, напрямую доступ к буферу не осуществляется.
Программа и составленные CMake-файлы конфигурации проекта работают корректно.
Для программы создано два файла CMakeLists.txt, один в основной директории, второй в директории src.
В файлах CPP в поле всех #include-директив используется только название файла, не должно быть #include-директив с указанием папки. Не допускается:
../include/.. .h
D:/.../include/.. .h**


Критерии оценки
Файлы CMakeLists.txt не содержат ошибок.
Программы запускаются и корректно работают, нет синтаксических ошибок.
Имена переменных корректные, отражают суть хранимых данных.
Создан текстовый интерфейс для всех программ.
Решения обеих задач структурированы и содержат заголовочные файлы.
Выполнено два задания.