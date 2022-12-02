#ifndef LAB4_OOP_BUILDINGS_H
#define LAB4_OOP_BUILDINGS_H
#include <queue>

/*!
* \brief Абстрактный класс постройки.
*/

class Building
{
protected:
    int _id;
    int _hp;
    int _max_hp;
    Cell* _location;
    int _level;
    int _level_max;
    char _building_type;
public:
    /*!
    * \brief Конструктор класса по умолчанию.
    */
    Building ();
    /*!
    * \brief Метод, возвращающий индекс постройки на игровом поле.
    * @return int Индекс.
    */
    [[nodiscard]] int GetId () const ;
    /*!
    * \brief Метод, возвращающий указатель на текущую ячейку постройки.
    * @return Cell* GetCurCell Ячейка.
    */
    Cell* GetCurCell ();
    /*!
    * \brief Метод, возвращающий тип постройки.
    * @return char Тип постройки.
    */
    [[nodiscard]] char GetBuildingType () const;
    /*!
    * \brief Метод, увеличивающий здоровье постройки.
    */
    void Heal ();
    /*!
    * \brief Метод, принимающий урон по постройке.
    * В качестве параметра принимает значение урона.
    * @param int damage.
    */
    void TakeDamage (int damage);
    /*!
    * \brief Виртуальный метод, повышающий уровень постройки.
    * @return bool Успех/Неудача.
    */
    virtual bool LevelUp () = 0;
    /*!
    * \brief Метод, удаляющий постройку с игрового поля.
    * В качестве параметра принимает ссылку на игровое поле.
    * @param World & world
    */
    void Destroy (World & world) const;
};

/*!
* \brief Класс-наследник класса Building. Тип постройки - замок.
*/

class Castle : public Building
{
public:
    /*!
    * \brief Конструктор класса.
    * В качестве параметров принимает ссылку на игровое поле и координаты спавна.
    * @param World & world, int x, int y
    */
    Castle (World & world, int x, int y);
    /*!
    * \brief Метод повышения уровня постройки.
    * @return bool Успех/Неудача.
    */
    bool LevelUp () override;
    /*!
    * \brief Метод, проверяющий, дошли ли сущности до замка.
    * В качестве параметров принимает ссылку на игровое поле.
    * @param World & world
    */
    void CheckEntities (World & world);
};

/*!
* \brief Класс-наследник класса Building. Тип постройки - башня.
*/

class Tower : public Building
{
private:
    int _damage;
    int _radius;
    double _reload;
    std::priority_queue <std::pair <int, Warrior*>, std::vector <std::pair <int, Warrior*>>, std::greater<>> _targets;
public:
    /*!
    * \brief Конструктор класса.
    * В качестве параметров принимает ссылку на игровое поле и координаты спавна.
    * @param World & world, int x, int y
    */
    Tower (World & world, int x, int y);
    /*!
    * \brief Метод, возвращающий урон башни.
    * @return int Урон.
    */
    [[nodiscard]] int GetDamage () const;
    /*!
    * \brief Метод, возвращающий радиус обстрела башни.
    * @return int Радиус.
    */
    [[nodiscard]] int GetRadius () const;
    /*!
    * \brief Метод, добавляющий цели в очередь обстрела башни.
    * В качестве параметров принимает ссылку на игровое поле.
    * @ World & world
    */
    void FindTargets (World & world);
    /*!
    * \brief Метод, наносящий урон сущности из очереди.
    */
    void DealDamage () const;
    /*!
    * \brief Метод повышения уровня постройки.
    * @return bool Успех/Неудача.
    */
    bool LevelUp () override;
};

/*!
* \brief Класс-наследник класса Building. Тип постройки - стена.
*/
class Wall : public Building
{
public:
    Wall (World & world, int x, int y);
    /*!
    * \brief Метод повышения уровня постройки.
    * @return bool Успех/Неудача.
    */
    bool LevelUp () override;
};

/*!
* \brief Класс-наследник класса Building. Тип постройки - Спавнер.
*/
class Spawner : public Building
{
private:
    int _count_troop;
    double _reload;
public:
    /*!
    * \brief Конструктор класса.
    * В качестве параметров принимает ссылку на игровое поле и координаты спавна.
    * @param World & world, int x, int y
    */
    Spawner (World & world, int x, int y);
    /*!
    * \brief Метод спавна сущности.
    * В качестве параметров принимает ссылку на игровое поле и тип сущности.
    * @param World & world, char unit_type
    */
    void SpawnUnit (World & world, char unit_type);
    /*!
    * \brief Метод повышения уровня постройки.
    * @return bool Успех/Неудача.
    */
    bool LevelUp () override;
};

#endif //LAB4_OOP_BUILDINGS_H
