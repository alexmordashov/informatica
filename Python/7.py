a = int(input('Введите число: '))
b = 1
for i in range(1, a + 1):
    b *= i
print(f'Факториал числа {a}: {b}')