<h4>Универсальный скалярный тип</h4>

<b>Скалярный тип данных</b> - содержит одно значение и не имеет внутренних компонентов. Скалярные типы данных делятся на четыре категории: <br>
 1) Числовые  <br>
 2) Символьные  <br>
 3) Даты (составные символы, строчные)  <br>
 4) Логические данные  <br>
 
<b>Универсальный скалярный тип</b> - такой тип, который может хранить в себе одно любое значение всех скалярных типов, значение могут меняться, и в любой момент запрашиваться<br>

<b>Основной алгоритм</b>: <br>
В C++ для динамической идентификации типов применяются операторы dynamic_cast и typeid (определён в файле typeinfo.h), для использования которых информацию о типах во время выполнения обычно необходимо добавить через опции компилятора при компиляции модуля.<br>

Оператор dynamic_cast пытается выполнить приведение к указанному типу с проверкой. Целевой тип операции должен быть типом указателя, ссылки или void*. <br>

* Если целевой тип — тип указателя, то аргументом должен быть указатель на объект класса. <br>
* Если целевой тип — ссылка, то аргумент должен также быть соответствующей ссылкой.
* Если целевым типом является void*, то аргумент также должен быть указателем, а результатом операции будет указатель, с помощью которого можно обратиться к любому элементу «самого производного» класса иерархии, который сам не может быть базовым ни для какого другого класса.

Оператор typeid возвращает ссылку на структуру type_info, которая содержит поля, позволяющие получить информацию о типе.

<b>Решения</b>: <br>

1. C использованием dinamic_cast (v1/supertype.h)
<img src="https://habrastorage.org/files/0c5/e3d/ef1/0c5e3def15a848eb84cd22db717494e4.png"/>
<br><br><br>
2. Без использования функции typeid() и прочих (v2/supertype.h)
<img src="https://habrastorage.org/files/ed9/a27/e63/ed9a27e63dca46aeab82cbcfcd979dcb.png"/>
<br><br><br>
3. Через перегрузку функций (собственный аналог typeinfo) (v3/supertype.h)
<img src="https://habrastorage.org/files/767/3bd/59a/7673bd59ab0a4110aa2a1561b77d0bd3.png"/>
<br><br><br>

