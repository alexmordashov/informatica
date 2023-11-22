a = int(input('Введите число: '))
b = a ** 0.5
for i in range(2, int(b + 1)):
    if a % 2 == 0 and a != 0:
        print('Не простое')
        exit()
print('Простое')