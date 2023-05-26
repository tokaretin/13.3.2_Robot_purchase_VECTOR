/*Задание 1
На витрине стоят несколько роботов, у каждого есть свой номер. 
Они задаются с клавиатуры (сначала вводится число n, потом -- n 
номеров роботов). Далее вводится число m и после этого -- m индексов 
(от 0 до количества оставшихся роботов на витрине). Когда введён 
очередной индекс -- робота покупают, то есть он покидает витрину, 
а остальные роботы “группируются”, смещаясь на один шаг назад. 
Необходимо вывести список оставшихся, после всех покупок, роботов.
 
Пример: на витрине стояли роботы {100, 200, 250, 300}. Сначала 
забрали робота с индексом 1, то есть с номером 200, осталось {100,250,300}. 
Потом забрали робота с индексом 1, то есть с номером 250, осталось {100,300}
 
Задание 2
Представим, что роботов могут не только покупать, забирая с витрины, 
но и “выставлять” в конец витрины. Пусть с клавиатуры вводят число K, а 
потом -- K запросов вида “1 n” и “2 m”. Запрос вида “1 n” означает, что
в конец витрины поставили робота номер n. Запроc “2 m” означает, что из
витрины забрали робота по индексу m. Необходимо смоделировать такое 
взаимодействие и после проведения всех запросов вывести на экран оставшихся 
на витрине роботов.*/

#include <iostream>
#include <vector>


int main() {
    int n;
    std::cout << "Enter the number of robots in the window: ";
    std::cin >> n;

    // Создаем вектор для хранения номеров роботов
    std::vector<int> robots(n);

    std::cout << "Enter the robot numbers: " << '\n';
    for (int i = 0; i < n; i++) {
        std::cin >> robots[i];
    }

    int k;
    std::cout << "Enter the number of queries: ";
    std::cin >> k;

    std::cout << "Type queries for the view \"1 n\" или \"2 m\": " << '\n';
    for (int i = 0; i < k; i++) {
        int queryType;
        std::cin >> queryType;

        if (queryType == 1) {
            int newRobot;
            std::cin >> newRobot;

            // Добавляем нового робота в конец витрины
            robots.push_back(newRobot);
        }
        else if (queryType == 2) {
            int index;
            std::cin >> index;

            // Проверяем, чтобы индекс был в допустимом диапазоне
            if (index >= 0 && index < robots.size()) {
                // Удаляем робота из витрины по указанному индексу
                robots.erase(robots.begin() + index);
            }
            else {
                std::cout << "Incorrect robot index. Skipping operation." << '\n';
            }
        }
        else {
            std::cout << "The request type is not valid. Skipping the operation." << '\n';
        }
    }

    std::cout << "Remaining robots: ";
    for (int i = 0; i < robots.size(); i++) {
        std::cout << robots[i] << " ";
    }
    std::cout << '\n';

    return 0;
}
