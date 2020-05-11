## СУБД
### Вариант 2
### БД - Совокупность факультетов (ВУЗ)
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
_некоторые из них вызывают функции из пространства имен helpingfuncs описанного в файлах helpingfuns_
**В этих же двух файлах описана и реализована функция поиска факультета внутри БД по названию, однако ее нельзя вызвать из
интерфейса, поскольку в задании не была указана реализация вызова этой функции из интерфейся**

#### Формат сохранения БД в файл
```cpp
<number_of_notes>
<type> <name> <science_center> <number_of_departments> { { <dep_name> { <lessnom_name> <number_of_teacher> } } }
...
```
В типах будет выглядеть так
```cpp
int
std::string std::string std::string int { { std::string { std::string int } } }
```
Коллекция определена следующим образом:
```cpp
std::map<std::string, std::map<std::string, int>>
```
**При этом все пробелы имеют большое значение, если хотя бы один будет пропущен, программа рабоать не будет**
Переменная типа "строка" <type> может иметь всего 2 значения "0" и "1" при этом сделана типом "строка" для удобства,
так как при введении неверного значения проще правильно бросить исключение и распознать неверный тип данных
#### Интерфейс СУБД
     **Для получения информации о формате ввода функций рекомендуется выполнить команду help**
1. Проверить работу функции "Создание БД" можно командой
```
create base_name
```
_Фуниция различает, какие БД мы хотим создать, гибридные или однотипные, поскольку мной была реализована система параметров,
однако, стоит отметить, что все БД созданные этой функцией являются гибридными, поскольку гибридная
БД является частным случаем однотипной_
    
2. Проверить работу функции "Вывод на экран* списка существующих БД." можно командой
```
print_base_list
```

3.  Проверить работу функции "Удаление* БД." можно командой
```
delete_base base_name
```

