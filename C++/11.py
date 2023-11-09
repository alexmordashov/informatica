a = input('Введите строку(латинские буквы):')
c = 0
str1 = 'aoieuy'
for i in a:
    if i.lower() in str1:
        c += 1
print(c)