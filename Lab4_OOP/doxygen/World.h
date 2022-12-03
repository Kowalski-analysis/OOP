#ifndef LAB4_OOP_WORLD_H
#define LAB4_OOP_WORLD_H
#include <map>
#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>
#include "../Images.h"

/*!
* \brief Класс ячейки игрового поля.
*/

class Cell
{
private:
    int _x;
    int _y;
    bool _lock;
    bool _air_lock;
    Cell* _go_to;
    Cell* _air_go_to;
    char _land_type;
public:
    /*!
    * \brief Конструктор класса по умолчанию.
    */
    Cell ();
    /*!
    * \brief Конструктор класса.
    * В качестве параметров принимает координаты ячейки на игровом поле.
    * @param int x, int y
    */
    Cell (int x, int y);
    /*!
    * \brief Метод, блокирующий наземное передвижение через ячейку.
    */
    void SetLock ();
    /*!
    * \brief Метод, разблокирующий назменое передвижение через ячейку.
    */
    void SetUnlock ();
    /*!
    * \brief Метод, блокирующий воздушное передвижение через ячейку.
    */
    void SetAirLock ();
    /*!
    * \brief Метод, разблокирующий воздушное передвижение через ячейку.
    */
    void SetAirUnlock ();
    /*!
    * \brief Метод, устанавливающий следующую по маршруту ячейку после текущей.
    * В качестве параметра принимает ссылку на следующую ячейку.
    * @param Cell & to
    */
    void SetWay (Cell & to);
    /*!
    * \brief Метод, устанавливающий тип ландшафта ячейки.
    * В качестве параметра принимает указатель на карту поля.
    * @param std::string* map
    */
    void SetLandType (std::string* map);
    /*!
    * \brief Метод, возвращающий указатель на следующую по маршруту ячейку после текущей.
    * @return Cell* Указатель на следующую ячейку.
    */
    [[nodiscard]] Cell* GetNextCell () const;
    /*!
    * \brief Метод, возвращающий указатель на следующую по воздушному маршруту ячейку после текущей.
    * @return Cell* Указатель на следующую ячейку.
    */
    [[nodiscard]] Cell* GetAirNextCell () const;
    /*!
    * \brief Метод, возвращающий координату Х ячейки.
    * @return int Координата X ячейки.
    */
    [[nodiscard]] int GetX () const;
    /*!
    * \brief Метод, возвращающий координату Y ячейки.
    * @return int Координата Y ячейки.
    */
    [[nodiscard]] int GetY () const;
    /*!
    * \brief Метод, возвращающий Манхэттеновское расстояние до ячейки target.
    * В качестве параметра принимает ссылку на ячейку-цель.
    * @param Cell & target
    * @return int Манхэттеновское расстояние.
    */
    [[nodiscard]] int GetManhattanDistance (Cell & target) const;
    /*!
    * \brief Метод, возвращающий вектор ячеек-соседей для текущей.
    * В качестве параметра принимает ссылку на вектор и ссылку на игровое поле.
    * @param World & world, std::vector <Cell*> & neighbors.
    * @return std::vector <Cell*> Вектор ячеек-соседей.
    */
    std::vector <Cell*> GetNeighbors (World & world, std::vector <Cell*> & neighbors) const;
    /*!
    * \brief Метод, возвращающий тип ландшафта ячейки.
    * @return char Тип ячейки.
    */
    [[nodiscard]] char GetLandType () const;
    /*!
    * \brief Метод, применяющий алгоритм A* для поиска кратчайшего пути к ячейке-цели.
    * Также расставляет поля Cell* _go_to/Cell* _air_go_to в необходимых ячейках.
    * В качестве параметров принимает ссылку на игровое поле и ссылку на ячейку-цель.
    * \warning Ячейка-цель должна существовать и быть доступной!
    */
    void A_star (World & world, Cell & target);
};

/*!
\brief Класс игрового поля.
*/

class World
{
private:
    int _size_x;
    int _size_y;
    std::vector <std::vector <Cell*>> _field;
    std::map <int, Building*> _buildings;
    std::map <int, Warrior*> _entities;
public:
    /*!
    * \brief Конструктор класса. В качестве параметров принимает размер игрового поля.
    * Реальные размеры поля устанавливаются как size + 2 (запас для границ поля)
    * @param size_x, size_y
    */
    World (int size_x, int size_y);
    /*!
    * Метод, возвращающий ширину игрового поля.
    * @return Ширина поля.
    */
    [[nodiscard]] int GetSizeX () const;
    /*!
    * Метод, возвращающий высоту игрового поля.
    * @return Высота поля.
    */
    [[nodiscard]] int GetSizeY () const;
    /*!
    * Метод, возвращающий контейнер с ячейками игрового поля.
    * @return std::vector <std::vector <Cell*>> & Контейнер с ячейками игрового поля.
    */
    std::vector <std::vector <Cell*>> & GetField ();
    /*!
    * Метод, возвращающий контейнер с постройками на игровом поле.
    * @return std::map <int, Building*> & Контейнер с постройками игрового поля.
    */
    std::map <int, Building*> & GetBuildings ();
    /*!
    * Метод, возвращающий контейнер с сущностями на игровом поле.
    * @return std::map <int, Warrior*> & Контейнер с сущностями игрового поля.
    */
    std::map <int, Warrior*> & GetEntities ();
    /*!
    * Метод, производящий считывание типов ячеек поля.
    */
    void ReadMap ();
    /*!
    * Метод, выводящий игровое поле (ландшафт) на экран.
    * @param sf::RenderWindow & window
    */
    void DrawLand (sf::RenderWindow & window);
    /*!
    * Метод, выводящий постройки на игровом поле на экран.
    * @param sf::RenderWindow & window
    */
    void DrawBuildings (sf::RenderWindow & window);
    /*!
    * Метод, выводящий сущности на игровом поле на экран.
    * @param sf::RenderWindow & window
    * @param float time
    */
    void DrawEntities (sf::RenderWindow & window, float time);
};

#endif //LAB4_OOP_WORLD_H
