def open_key(a, K, n):
    Y = (a**K)%n
    return Y

def secret_key(Y,K,n):
    new_K = (Y**K)%n
    return new_K

def checking_key(a, n, Ka, Kb):
    Ya = open_key(a, Ka, n)
    Yb = open_key(a, Kb, n)
    K_1 = secret_key(Yb, Ka, n)
    K_2 = secret_key(Ya, Kb, n)
    if (K_1 == K_2 != 1):
        return f'Общий ключ: {K_1}. Все верно'
    else:
        return f'Ошибка! Ka = {K_1}, Kb = {K_2}'
    
def main():
    print('Обмен ключами по Диффи-Хелману')
    what_to_do = int(input('Что делать?\
                     \n1.Проверка общего ключа\n'))
    while True:
        n = int(input('Введите n > 1: '))
        if n <= 1:
            print('n должно быть больше 1')
        else:
            break
    while True:
        a = int(input(f'Введите a, такое что 1 < a < {n}: '))
        if ((a <= 1) or (a >= n)):
            print(f'a должно соответствовать условию: 1 < a < {n}')
        else:
            break
    if what_to_do == 3:
        while True:
            Ka = int(input(f'Введите Ka, такое что 2 < Ka < {n-1}: '))
            if ((Ka <= 2)or(Ka >= n-1)):
                print(f'Ka должно соответствовать условию: 2 < Ka < {n-1}')
            else:
                break
        print(f'Открытый ключ: {open_key(a, Ka, n)}')
    elif what_to_do == 2:
        while True:
            Ka = int(input(f'Введите Ka, такое что 2 < Ka < {n-1}: '))
            if ((Ka <= 2)or(Ka >= n-1)):
                print(f'Ka должно соответствовать условию: 2 < Ka < {n-1}')
            else: 
                break
        Yb = int(input('Введите открытый ключ другого пользователя: '))
        print(f'Общий секретный ключ(K): {secret_key(Yb, Ka, n)}')
    elif what_to_do == 1:
        while True:
            Ka = int(input(f'Введите Ka, такое что 2 < Ka < {n-1}: '))
            if ((Ka <= 2)or(Ka >= n-1)):
                print(f'Ka должно соответствовать условию: 2 < Ka < {n-1}')
            else:
                break
        while True:
            Kb = int(input('Введите Kb: '))
            if ((Kb <= 2)or(Kb >= n-1)):
                print(f'Kb должно соответствовать условию: 2 < Kb < {n-1}')
            else:
                break
        print(checking_key(a, n, Ka, Kb))
        
