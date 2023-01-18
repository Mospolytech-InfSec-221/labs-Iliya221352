#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;




void palindrom(char* s){
    setlocale(LC_ALL, "Russian");
    int n = strlen(s);
    char* z = nullptr;
    char* g = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            z += tolower(s[i]);
        }
    }
    for (int i = 0; i < n; i++){
        if (s[i] != ' '){
            g += tolower(s[i]);
        }

    }
    z += '\0';
    g += '\0';
   // cout << (z == g);
    if (z==g) {
        cout << "Строка является палиндромом";
    }else{
        cout << "Строка не является палиндромом";
    }
}


int find_substring1(const char* s, char* substring) {
    int size = strlen(s);
    int size1 = strlen(substring);
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] == substring[j]) {
            j++;
        }
        else {
            j = 0;
        }
        if (j == size1) {
            return i - j + 1;
        }
    }
}
int* find_substring2(const char* s, const char* substring) {
    int size = strlen(s);
    int size1 = strlen(substring);
    int j = 0;
    int q = 0;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        if ((s[i] == substring[j]) and (j < size1)) {
            j++;
        }
        else {
            j = 0;
        }
        if (j == size1 - 1) {
            arr[q] = i - j + 1;
            q++;
            j = 0;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << arr[i] << endl;
    }
    return arr;
}
void cesar(char *s, int key) {
    char* str = s;
    for (int i = 0; i < strlen(str); i++)
    {
        if (int(str[i]) == 32)
        {
            str[i] = char(int(str[i]));
        }
        else
        {
            str[i] = char(int(str[i]) + key);
            if (int(str[i] > 122)) str[i] = char(int(str[i]) - 26);
            if ((int(str[i]) > 90) and (str[i] < 97)) str[i] = char(int(str[i]) - 26);
        }
    }
    cout << str;
}

void task_5(char* str) {
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '"')
        {
            i++;

            while (str[i] != '"')
            {
                cout << str[i];
                i++;
            }
            cout << " ";
        }
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    char text[255] = {'\0'};
    cin.getline(text, 255);
    cout << text <<strlen(text)<<endl;
    while (true) {
        int m;
        std::cout << "Что вы хотите выполнить? \n"
            << "1. Является ли строка палиндромом?\n"
            << "2. Найти начало подстроки\n"
            << "3. Найти все подстроки в строке\n"
            << "4. Шифр Цезаря\n"
            << "5. Что написано в ковычках\n";
        std::cin >> m;
        switch (m) {
            case 1: {
                palindrom(text);
                cout << "\n\n\n";
                break;
            }
            
            case 2: {
                cout << "Введите подстроку которую будем искать"<<endl;
                char substr[] = {'\0'};
                cin.ignore();
                cin.getline(substr, 255);
                cout << substr << endl;
                cout << find_substring1(text, substr);
                break;
            }
            case 3: {
                cout << "Введите подстроку которую будем искать" << endl;
                char substr[] = { '\0' };
                cin.ignore();
                cin.getline(substr, 255);
                cout << substr << endl;
                int *arr = find_substring2(text, substr);
                break;
            }
            case 4: {
                int key;
                cin >> key;
                cesar(text, key);
            }
            case 5: {
                cout << "Вывод значений в кавычках" << endl;
                task_5(text);
                break;
            }
        }

    }
}