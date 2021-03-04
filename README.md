# DrWebTest
Dr.Web test assignment

Results of third exercise benchmarking:

![Benchmark](https://github.com/UberDever/DrWebTest/blob/master/Benchmarks.jpg)

## Tasks

1) Матрица (C)
Нужно реализовать функцию на C, на вход которой подается матрица M x N.

1) Отсортировать по убыванию элементы в каждом столбце (N элементов)
2) Отсортировать по убыванию элементы в каждой строку (M элементов)
3) Вернуть результат, не меняя входной буффер

* использовать готовые функции для сортировки нельзя.

Сигнатура реализуемой функции:
int **generate(const int **matrix, size_t m, size_t n);

2) Матрица (C++)
Реализовать все то же самое на С++, используя один из контейнеров STL с
непрерывной организацией памяти. Сигнатуру функции модифицировать
соответственно (использовать контейнер для входных данных и возврата
результата).

3) Шифр Цезаря (C++)
Дана функция шифрования строки шифром Цезаря:

```
#include <ostream>
#include <iostream>

std::wstring get_ceasar_string(std::wstring str) {

     const wchar_t shift = 3;

     std::wstring res;

     for (size_t i = 0; i < str.size(); i++) {

         if (str[i] >= L'a' && str[i] <= L'z') {
             res += L'a' + (str[i] - L'a' + shift) % (L'z' - L'a' + 1);
             continue;
         }

         if (str[i] >= L'A' && str[i] <= L'Z') {
             res += L'A' + (str[i] - L'A' + shift) % (L'z' - L'a' + 1);
             continue;
         }

         res += str[i];
     }

     return res;
}

int main() {

     std::wstring str = L"Somebody once told me the world is gonna roll
me!";
     std::wstring str_crypted = get_ceasar_string(str);
     std::wcout << str_crypted << std::endl;

     return 0;
}
```

Оптимизируйте функцию get_ceasar_string() насколько возможно (стандарт
до С++17 включительно) и напишите пояснения к изменениям.

4) Цензура (C++)
Реализовать класс, наследующийся от std::string, который отличается от
него только ограничением: методом swap() нельзя присвоить строку,
содержащую "dr.web" (в любом регистре). Если присваиваемая строка все же
содержит эту подстроку, выбросить исключение "std::invalid_argument"
