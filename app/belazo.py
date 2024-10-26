from functions import encoding_format, normal_text, input_text

def Belazo_enc(n, key_word):  # Шифр Белазо шифрование
    text = ''
    new_text = encoding_format(text)
    # n = n.replace(',', 'зпт').replace(' ', 'прб').replace('.', 'тчк')  # Замена символов
    for counter in range(len(n)):
        i = alf.find(n[counter])  # Ищем букву открытого текста в алфавите
        j = alf.find(key_word[counter % len(key_word)])
        new_text += alf[((i + j) % 32)]  # Находим соответствующую букву для шифртекста
    return new_text

def Belazo_dec(n, key_word):  # Шифр Белазо расшифрование
    text = ''
    # n = n.replace(',', 'зпт').replace(' ', 'прб').replace('.', 'тчк')  # Замена символов
    for counter in range(len(n)):
        i = alf.find(n[counter])  # Ищем букву шифртекста в алфавите
        j = alf.find(key_word[counter % len(key_word)])  # Находим соответствующую букву для открытого текста
        text += alf[(i - j) % 32]
    new_text = normal_text(text)
    # decrypted_text = new_n.replace('прб', ' ').replace('зпт', ',').replace('тчк', '.')  # Замена символов обратно при расшифровании 
    return new_text

alf = 'абвгдежзийклмнопрстуфхцчшщъыьэюя'  # Алфавит

def main():
    print("Шифр Белазо.")
    action = int(input("Выберите действие:\n 1) Зашифровать\n 2) Расшифровать\n"))
    if action == 1:
        text = input_text()
        text = encoding_format(text)
        key_word = input("Введите слово-ключ:")
        result = Belazo_enc(text, key_word)  # Шифруем введенный текст методом атбаша
        print("Шифротекст:", result)
    # Расшифрование.
    elif action == 2:
        text = input_text()
        key_word = input("Введите слово-ключ:")
        result = normal_text(Belazo_dec(text, key_word))
        print('Расшифрованный текст:', result)
    else:
        print("Некорректный ввод.")

# main()




