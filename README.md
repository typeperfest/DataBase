# СУБД
## Вариант 2
## БД - Совокупность факультетов (ВУЗ)
Реализованные классы лежат в файле FacultyClasses.h
У абстракного класса 3 чистых виртуальных функции
* Функция, вычисляющая количество дисциплин для факультета 
* Функция, нужная только для класса отраслевого факультета, геттер по которому можно получить вторую коллекцию
* Функция, нужная только для класса отраслевого факультета, сеттер, с помощью которого можно установить вторую коллекцию

Последние две функции - вынужденная мера, так как только через них есть возможность обратиться ко второй коллекции,
в случае, когда было использовано приведение типов к более старшему классу
Все текстовые команды, весь парсинг введенных команд находятся в мейн файле.
Взамодействие с консолью производится по принципу bash shell, именно им я вдохновлялся когда разрабатывал интерфейс.
В бесконечном цикле в мейн файле производится обработка введенных строк, бросаются неоходимые исключения (о них позже)
после того как были получены необходимые параметры, вызываются функции (основные функции находящиеся в задании в пункте 5)
из пространства имен cf (console functions), функции объявлены в файле consolefunctions.h и описаны в файле consoleFunctions.cpp
_некоторые из них вызывают функции из пространства имен helpingfuncs описанного в файлах helpingfuns_.
**В этих же двух файлах описана и реализована функция поиска факультета внутри БД по названию, однако ее нельзя вызвать из
интерфейса, поскольку в задании не была указана реализация вызова этой функции из интерфейся**

---
В папке Bases внутри папки с проектом есть две готовых БД для проверки работы
---

### Формат сохранения БД в файл
```cpp
<number_of_notes>
<type> <name> <science_center> <number_of_departments> { { <dep_name> { <lessnom_name> <number_of_teacher> } } }
...
```
В типах будет выглядеть так
```cpp
int
std::string std::string std::string int { { std::string { std::string int } } }
std::string std::string std::string int { { std::string { std::string int } } }
...
std::string std::string std::string int { { std::string { std::string int } } }
```
Коллекция определена следующим образом:
```cpp
std::map<std::string, std::map<std::string, int>>
```
**При этом все пробелы имеют большое значение, если хотя бы один будет пропущен, программа рабоать не будет**
Переменная типа "строка" <type> может иметь всего 2 значения "0" и "1" при этом сделана типом "строка" для удобства,
так как при введении неверного значения проще правильно бросить исключение и распознать неверный тип данных
### Интерфейс СУБД
     **Для получения информации о формате ввода функций рекомендуется выполнить команду help**
1. Проверить работу функции "Создание БД" можно командой (строка 58 мейн файла)
```
create base_name
```
_Фуниция различает, какие БД мы хотим создать, гибридные или однотипные, поскольку мной была реализована система параметров,
однако, стоит отметить, что все БД созданные этой функцией являются гибридными, поскольку гибридная
БД является частным случаем однотипной_
    
2. Проверить работу функции "Вывод на экран* списка существующих БД." можно командой (строка 94 мейн файла)
```
print_base_list
```

3.  Проверить работу функции "Удаление* БД." можно командой (строка 106 мейн файла)
```
delete_base base_name
```

4. Проверить работу функции "Переименование* БД." можно командой (строка 128 мейн файла)
```
rename base_name_1 base_name_2
```

Предыдущие 3 функции были реализованы с использованием Filesystem Library функции которой ~~как выяснилось спустя 3 часа~~ лежат
внутри std::experimental

5. Проверить работу функции "Открытие** БД." можно командой (строка 153 мейн файла)
```
open base_name
```
6. Проверить работу функции "Сохранение** БД." можно командой (строка 174 мейн файла)
```
save base_file_name
```
Фичей данной функции является то, что сохранить БД можно как и в тот файл, из которого она открыта, так и другой файл

7. Проверить работу функции "Добавление записей в БД." можно командой (строка 198 мейн файла)
```
add
```
**Команда будет работать только в том случае, если в данный момент открыта БД**

Эта функция падает, если не следовать указаниям на экране и вводить некоторые данные с пробелами, а кое-где без,
Отладить до идеала можно и несложно, но будет много лишнего кода, затрудняющего проверку

Формат ввода данных в помощь:
```
1          // Тип факультета
name       // Имя факультета
scice      // Hук
2          // Количество кафедр
kaf1       // Имя 1 кафедры
2          // Количество предметов
les1 4     // Имя первого предмета и число преподавателей ЧЕРЕЗ ПРОБЕЛ
les2 5     // То же самое для 2 предмета
kaf2       // Имя 2 кафедры
2          // Количество предметов
les3 10    // Имя первого предмета и число преподавателей ЧЕРЕЗ ПРОБЕЛ
les4 15    // То же самое для 2 предмета
```

8. Проверить работу функции "Редактирование записей в БД." можно командой (строка 217 мейн файла)
```
edit
```
Работает почти полностью так же как и предыдущая команда, использует такой же формат ввода
Разница лишь в том что в начале надо будет выбрать какая именно запись будет заменена на новую

**Команда будет работать только в том случае, если в данный момент открыта БД**

9. Проверить работу функции "Удаление записей в БД." можно командой (строка 234 мейн файла)
```
delete_note
```
Необходимо будет выбрать, какая запись должна быть удалена

**Команда будет работать только в том случае, если в данный момент открыта БД**

10. Проверить работу функции "Вывод на экран записей БД." можно командой (строка 250 мейн файла) 
```
print_notes
```
**Команда будет работать только в том случае, если в данный момент открыта БД**

11. Проверить работу функции "Сортировка записей БД." можно командами (строка 264 мейн файла)
По возрастанию и по имени факультета
```
sort :byname inc
```

По убыванию и по имени факультета
```
sort :byname dec
```

По возрастанию и по числу кафедр
```
sort :bdnumber inc
```

По убыванию и по числу кафедр
```
sort :byname dec
```
После команды рекомендуется выполнить print_notes для того чтобы увидеть результат

**Команда будет работать только в том случае, если в данный момент открыта БД**

12. Проверить работу функции "Выборка записей БД по правилу (значению поля)." можно командой (строка 314 мейн файла)

По предмету, который ведет кафедра
```
choose :byles
```

Больше чем число кафедр, введенное с клавиатуры (вводится после этой команды)
```
choose :mn
```

**Команда будет работать только в том случае, если в данный момент открыта БД**

13. Проверить работу функции "Сохранение** выборки как новой БД." можно командой (строка 363 мейн файла)
``` 
transmit_new_base base_name
```
Комбинация команд create, choose и save

**Команда будет работать только в том случае, если была произведена выборка из БД**

В скобках указаны строки, с которых начинается реализация функций, основные их тела лежат по порядку в файле consoleFunctions.cpp
