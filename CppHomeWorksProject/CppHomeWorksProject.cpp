#include <iostream>

int MenuComponents();
int MenuActions();

void Complect(unsigned char complect);

unsigned char AddComponent(unsigned char complect, int number);
unsigned char RemoveComponent(unsigned char complect, int number);

void HW1();


int main()
{
    srand(time(nullptr));

    const int size{ 5 };
    const int sizeBig{ 2 * size };
    int array[sizeBig]{};

    for (int i{}; i < sizeBig; i++)
        array[i] = rand() % 100;
    for (int i{}; i < sizeBig; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";

    int indexMax{};
    int sumMax{ array[indexMax] };
    
    for (int i{}; i <= size; i++)
    {
        int sum{};
        for (int j{ i }; j < i + size; j++)
            sum += array[j];
        if (sum > sumMax)
        {
            sumMax = sum;
            indexMax = i;
        }

        std::cout << "index = " << i << "\n";
        std::cout << "summa = " << sum << "\n\n";
    }

    std::cout << "\n";

    std::cout << "Max array index = " << indexMax << "\n";
    std::cout << "Max array summa = " << sumMax << "\n";

    std::cout << "=======================================\n";

    int summaMax{};
    for (int i{}; i < size; i++)
        summaMax += array[i];
    int indexMaximum{ 0 };

    std::cout << "index = " << indexMaximum << "\n";
    std::cout << "summa = " << summaMax << "\n\n";

    for (int i{ 1 }; i <= size; i++)
    {
        int summaNew = summaMax - array[i - 1] + array[i + size - 1];
        if (summaNew > summaMax)
        {
            summaMax = summaNew;
            indexMaximum = i;
        }

        std::cout << "index = " << i << "\n";
        std::cout << "summa = " << summaNew << "\n\n";
    }
    
    std::cout << "index = " << indexMaximum << "\n";
    std::cout << "summa = " << summaMax << "\n\n";
}

int MenuComponents()
{
    int choise;

    std::cout << "1 Одноядерный процессор / Многоядерный процессор\n";
    std::cout << "2 Отсутствие / Наличие  DVD - ROM\n";
    std::cout << "3 Отсутствие / Наличие отдельной сетевой платы\n";
    std::cout << "4 Отсутствие / Наличие отдельной звуковой платы\n";
    std::cout << "5 Отсутствие / Наличие отдельной видеоплаты\n";
    std::cout << "6 Обычный жесткий диск(HDD) / твердотельный(SSD)\n";
    std::cout << "7 Один / два монитора\n";
    std::cout << "8 Проводные / беспроводные клавиатура и мышь\n";

    std::cout << "Ваш выбор: ";
    std::cin >> choise;

    return choise;
}

int MenuActions()
{
    int choise;
    std::cout << "1 Добавить\n";
    std::cout << "2 Удалить\n";
    std::cout << "0 Завершить комплектацию\n";

    std::cout << "Ваш выбор: ";
    std::cin >> choise;

    return choise;
}

void Complect(unsigned char complect)
{
    for (int i{}; i < 8; i++)
    {
        int mask = (1 << i);
        switch (i)
        {
        case 0: 
            std::cout << (!(complect && mask) ? "Одноядерный процессор" : "Многоядерный процессор") << "\n";
            break;
        case 1:
            std::cout << (!(complect && mask) ? "Отсутствие" : "Наличие") << " DVD - ROM\n";
            break;
        case 2:
            std::cout << (!(complect && mask) ? "Отсутствие" : "Наличие") << " сетевой платы\n";
            break;
        case 3:
            std::cout << (!(complect && mask) ? "Отсутствие" : "Наличие") << " звуковой платы\n";
            break;
        case 4:
            std::cout << (!(complect && mask) ? "Отсутствие" : "Наличие") << " видеоплаты\n";
            break;
        case 5:
            std::cout << (!(complect && mask) ? "Обычный" : "Твердотельный") << " жесткий диск\n";
            break;
        case 6:
            std::cout << (!(complect && mask) ? "Один монитор" : "Два монитора") << "\n";
            break;
        case 7:
            std::cout << (!(complect && mask) ? "Проводные" : "Беспроводные") << " клавиатура и мышь\n";
            break;
        default:
            break;
        }
    }
}

unsigned char AddComponent(unsigned char complect, int number)
{
    unsigned char mask = 1 << (number - 1);

    //complect = complect | mask;
    complect |= mask;

    return complect;
}

unsigned char RemoveComponent(unsigned char complect, int number)
{
    unsigned char mask = 1 << (number - 1);
    
    //complect = complect & ~mask;
    complect &= ~mask;

    return complect;
}

void HW1()
{
    setlocale(LC_ALL, "Russian");

    unsigned char complect{};
    int action;
    int component;



    while (1)
    {
        Complect(complect);
        std::cout << "\n";

        component = MenuComponents();
        std::cout << "\n";

        action = MenuActions();
        std::cout << "\n";

        if (!action) break;

        if (action == 1)
            complect = AddComponent(complect, component);

        if (action == 2)
            complect = RemoveComponent(complect, component);
    }

    Complect(complect);
    std::cout << "\n";
}