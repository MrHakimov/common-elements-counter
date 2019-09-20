# common-elements-counter

## Problem statement in English
It is necessary to write code that effectively finds the number of common elements in two arrays of ints. We can assume that the elements inside each array are not repeated. Pay attention to the case when one list is much smaller than the other in size. In addition, you must write code that tests the correctness of the algorithm.

What will be evaluated:
1. The correctness of the algorithm.
2. The speed of work. Not only the asymptotic run time is important, but also the constant hidden in it.
3. The completeness of the tests. An incorrectly written algorithm should not pass your test.
4. Code readability.

In a few sentences, describe the algorithm used, which alternatives are available and why your algorithm is better.

### Algorithm Description
Two arrays are given. Let the size of the smaller array be equal to `n`, and the size of the larger array be equal to` m`. Sort the array with a smaller size - `O (n log (n))`. Now, going over a larger array, we will check if there is a current element from a larger array in a smaller one. This can be done in `O (m log (n))` using the binary search method, since the smaller array is sorted. And therefore, if the current element from the larger array is in the smaller one, then increase the counter value by 1. Total, the general asymptotic behavior of the algorithm is equal to `O ((n + m) log (n))`.

### Alternatives
1. ** Naive implementation - brute-force**. The asymptotic run time of such an implementation is very large - `O (nm)`. I use it to verify the correctness of the algorithm above.
2. ** Use set and thus get rid of explicit binary search **. Asymptotic runtime will not change, however, such an implementation uses additional memory. However, using set, you can write an algorithm that works not only for arrays with various elements. To do this, it is enough to remove the element from the smaller array if it was detected while passing through the larger array in `O (log (n))`, which does not change the general asymptotic behavior of the algorithm.
3. ** Use unordered_set **. On average, such an implementation will work faster than my algorithm, since adding and searching in it is amortized for `O (1)`, but on some input it can reach `O ((n + m) n)`, and additional memory is also used.

---
## Условие задания на русском
Необходимо написать код, который эффективным образом найдёт количество общих элементов в двух массивах int-ов. Можно считать, что элементы внутри каждого массива не повторяются. Уделите внимание случаю, когда один список намного меньше другого по размеру. Кроме того, необходимо написать код, который тестирует правильность алгоритма. 

Что будет оцениваться: 
1. Правильность работы алгоритма. 
2. Скорость работы. Важна не только асимптотика, но и скрытая в ней константа. 
3. Полнота тестов. Неправильно написанный алгоритм не должен проходить ваш тест. 
4. Читаемость кода. 

В нескольких предложениях опишите используемый алгоритм, какие есть альтернативы и почему ваш алгоритм лучше. 

Рекомендуется использовать C++, но другие языки программирования тоже допустимы.

### Описание алгоритма
Дано два массива. Пусть размер меньшего массива равен `n`, а размер большего массива равен `m`. Отсортируем массив с меньшим размером - `O(n log(n))`. Теперь, пробегаясь по большему массиву будем проверять есть ли текущий элемент из большего массива в меньшем. Это можно сделать за `O(m log(n))` воспользовавшись методом двоичного поиска, так как меньший массив отсортирован. И поэтому, если текущий элемент из большего массива есть в меньшем, то увеличим значение счетчика на 1. Итого, общая асимптотика алгоритма равна `O((n + m) log(n))`.

### Альтернативы
1. **Наивная реализация - перебор**. Асимптотическое время работы такой реализации очень большое - `O(nm)`. Ее я использую для проверки корректности алгоритма, приведенного выше.
2. **Использовать set и таким образом избавиться от явного двоичного поиска**. Асимптотическое время работы не изменится, однако такая реализация использует дополнительную память. Однако, использовав set можно написать алгоритм, работающий не только для массивов с различными элементами. Для этого достаточно удалять элемент из меньшего массива, если он был обнаружен при проходе по большему массиву за `O(log(n))`, что не изменит общую асимптотику алгоритма.
3. **Использовать unordered_set**. В среднем такая реализация будет работать быстрее, чем приведенный мною алгоритм, так как амортизированно добавление и поиск в нем работает за `O(1)`, однако на некоторых входных данных может достигать `O((n + m) n)`, и так же используется дополнительная память.
