#ifndef LAB4_OOP_ENTITIES_H
#define LAB4_OOP_ENTITIES_H
#include <ctime>
#include <iostream>

/*!
* \brief Абстрактный класс сущности.
*/

class Warrior
{
protected:
    float _x;
    float _y;
    int _id;
    int _hp;
    double _velocity;
    int _damage;
    int _level;
    int _max_level;
    Cell* _cur_cell;
public:
    /*!
    * Конструктор класса по умолчанию
    */
    Warrior ();
    /*!
    * \brief Метод, возвращающий текующую координату Х сущности на экране.
    * @return float Координата Х на экране
    */
    [[nodiscard]] float GetX () const;
    /*!
    * \brief Метод, возвращающий текующую координату У сущности на экране.
    * @return float Координата У на экране
    */
    [[nodiscard]] float GetY () const;
    /*!
    * \brief Метод, возвращающий индекс сущности.
    * @return int Индекс
    */
    [[nodiscard]] int GetId () const;
    /*!
    * \brief Метод, возвращающий здоровье сущности.
    * @return int Здоровье
    */
    [[nodiscard]] int GetHp () const;
    /*!
    * \brief Метод, возвращающий урон сущности.
    * @return int Урон
    */
    [[nodiscard]] int GetDamage () const;
    /*!
    * \brief Метод, возвращающий указатель на текущую ячейку сущности.
    * @return Cell* Текущая ячейка
    */
    Cell* GetCurCell ();
    /*!
    * \brief Метод, изменяющий координату Х на экране сущности.
    * В качестве параметра принимает изменение координаты X.
    * @param float x
    */
    void AddtoX (float x);
    /*!
    * \brief Метод, изменяющий координату Y на экране сущности.
    * В качестве параметра принимает изменение координаты Y.
    * @param float y
    */
    void AddtoY (float y);
    /*!
    * \brief Метод, удаляющий сущность из игрового поля.
    * В качестве параметра принимает ссылку на игровое поле.
    * @param World & world
    */
    void Die (World & world) const;
    /*!
    * \brief Метод, наносящий урон постройке building.
    * В качестве параметра принимает ссылку на постройку.
    * @param Building & building
    */
    void DealDamage (Building & building) const;
    /*!
    * \brief Метод, принимающий урон.
    * В качестве параметра принимает размер урона.
    * @param int damage
    */
    void TakeDamage (int damage);
    /*!
    * \brief Метод, перемещающий сущность в следующую по маршруту ячейку.
    */
    void Move ();
    /*!
    * \brief Метод, возвращающий пару множителей направления в зависимости от следующей по маршруту ячейки.
    * @return std::pair <float, float> Пара множителей.
    */
    std::pair <float, float> DirectionOfNextCell ();
    /*!
    * \brief Виртуальный метод, повышающий уровень сущности.
    * @return bool Успех/Неудача
    */
    virtual bool LevelUp () = 0;
};

    /*!
    * \brief Класс-наследник класса Warrior. Сущность - легкая пехота.
    */

class Knight : public Warrior
{
public:
    /*!
    * \brief Конструктор класса.
    * В качестве параметров принимает ссылку на игровое поле и координаты спавна сущности.
    * @param World & world, int x, int y
    */
    Knight (World & world, int x, int y);
    /*!
    * \brief Метод, определяющий уклоенеие от входящего урона.
    * @return bool Уклонение/Не уклонение.
    */
    static bool AvoidDamage ();
    /*!
    * \brief Метод повышения уровня сущности.
    * @return bool Успех/Неудача.
    */
    bool LevelUp () override;
};

    /*!
    * \brief Класс-наследник класса Warrior. Сущность - тяжелая пехота.
    */

class Juggernaut : public Warrior
{
public:
    /*!
    * \brief Конструктор класса.
    * В качестве параметров принимает ссылку на игровое поле и координаты спавна сущности.
    * @param World & world, int x, int y
    */
    Juggernaut (World & world, int x, int y);
    /*!
    * \brief Метод повышения уровня сущности.
    * @return bool Успех/Неудача.
    */
    bool LevelUp () override;
};

    /*!
    * \brief Класс-наследник класса Warrior. Сущность - авиация.
    */
class Aviation : public Warrior
{
public:
    /*!
    * \brief Конструктор класса.
    * В качестве параметров принимает ссылку на игровое поле и координаты спавна сущности.
    * @param World & world, int x, int y
    */
    Aviation (World & world, int x, int y);
    /*!
    * \brief Метод повышения уровня сущности.
    * @return bool Успех/Неудача.
    */
    bool LevelUp () override;
};

    /*!
    * \brief Класс-наследник класса Warrior. Сущность - герой.
    */

class Hero : public Warrior
{
private:
    int _aura_radius;
public:
    /*!
    * \brief Конструктор класса.
    * В качестве параметров принимает ссылку на игровое поле и координаты спавна сущности.
    * @param World & world, int x, int y
    */
    Hero (World & world, int x, int y);
    /*!
    * \brief Метод возвращающий радиус ауры сущности.
    * @return int Радиус.
    */
    [[nodiscard]] int GetAuraRadius () const;
    /*!
    * \brief Метод повышения уровня сущности.
    * @return bool Успех/Неудача.
    */
    bool LevelUp () override;
    /*!
    * \brief Метод воздействия ауры сущности на другие сущности на игровом поле.
    * @return bool Успех/Неудача.
    */
    void AuraEffect (World & world);
};

#endif //LAB4_OOP_ENTITIES_H
