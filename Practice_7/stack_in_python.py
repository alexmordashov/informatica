arr = []
while True:
    a = input('Что хотите сделать?\n1. Добавить элемент\n2. Извлечь элемент\n3. Ничего')
    if a == '1':
        arr.append(input('Введите элемент:'))
        print(arr)
    elif a == '2':
        if len(arr) != 0:
            print('Извлечен элемент:', arr.pop())
            print(arr)
        else:
            print('Стек пуст')
    else:
        exit()
