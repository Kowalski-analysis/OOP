#include "gtest/gtest.h"
#include "World.h"
#include "Buildings.h"
#include "Entities.h"

/// Class Cell

TEST (Cell_Constructor, Default)
{
    Cell C;
    ASSERT_EQ (C.GetX(), 0);
    ASSERT_EQ (C.GetY(), 0);
    ASSERT_EQ (C.GetNextCell(), nullptr);
    ASSERT_EQ (C.GetAirNextCell(), nullptr);
    ASSERT_EQ (C.GetLandType(), ' ');
}

TEST (Cell_Constructor, Coordinates)
{
    Cell C(5, 5);
    ASSERT_EQ (C.GetX(), 5);
    ASSERT_EQ (C.GetY(), 5);
    ASSERT_EQ (C.GetNextCell(), nullptr);
    ASSERT_EQ (C.GetAirNextCell(), nullptr);
    ASSERT_EQ (C.GetLandType(), ' ');
}

TEST (Cell_Methods, SetLock_SetUnlock_GetLock)
{
    Cell C;
    C.SetUnlock();
    ASSERT_EQ(C.GetLock(), false);
    C.SetLock();
    ASSERT_EQ(C.GetLock(), true);
}

TEST (Cell_Methods, SetAirLock_SetAirUnlock_GetAirLock)
{
    Cell C;
    C.SetAirUnlock();
    ASSERT_EQ(C.GetAirLock(), false);
    C.SetAirLock();
    ASSERT_EQ(C.GetAirLock(), true);
}

TEST (Cell_Methods, SetWay_GetNextCell)
{
    Cell C;
    C.SetWay(C);
    ASSERT_EQ(&C, C.GetNextCell());
}

TEST (Cell_Methods, SetAirWay_GetAirNextCell)
{
    Cell C;
    C.SetAirWay(C);
    ASSERT_EQ(&C, C.GetAirNextCell());
}

TEST (Cell_Methods, SetLandType_GetLandType)
{
    Cell C(0,0);
    std::string arr1[2] = {"ab","ab"};
    C.SetLandType(arr1);
    ASSERT_EQ('a', C.GetLandType());
    ASSERT_EQ(C.GetLock(), false);
    std::string arr2[2] = {"jj", "jj"};
    C.SetLandType(arr2);
    ASSERT_EQ(C.GetLandType(), 'j');
    ASSERT_EQ(C.GetLock(), true);
    ASSERT_EQ(C.GetAirLock(), false);
}

TEST (Cell_Methods, GetX_GetY)
{
    Cell C(3, 4);
    ASSERT_EQ(C.GetX(), 3);
    ASSERT_EQ(C.GetY(), 4);
}

TEST (Cell_Methods, GetManhattanDistance)
{
    Cell C1(1, 1);
    Cell C2(10, -7);
    ASSERT_EQ(C1.GetManhattanDistance(C2), 17);
}

World W(10, 10);

TEST (Cell_Method, A_star)
{
    W.GetField()[1][1]->A_star(W, *W.GetField()[7][3]);
    auto i = W.GetField()[1][1];
    while (i != W.GetField()[7][3])
    {
        i = i->GetNextCell();
    }
}

TEST (Cell_Method, GetNeighbors)
{
    std::vector <Cell*> vec;
    W.GetField()[5][4]->SetLock();
    W.GetField()[5][5]->GetNeighbors(W, vec);
    ASSERT_EQ(vec.size(), 3);
}

/// Class World

TEST (World_Constructor_and_Getters, Coordinates)
{
    ASSERT_EQ(W.GetSizeX(), 12);
    ASSERT_EQ(W.GetSizeY(), 12);
    ASSERT_EQ(W.GetField().size(), 12);
    ASSERT_EQ(W.GetField()[1].size(), 12);
    ASSERT_EQ(W.GetBuildings().size(), 3);
    ASSERT_EQ(W.GetEntities().size(), 4);
}

/// Class Castle and Building

Castle C(W, 7, 7);

TEST (Castle_Constructor_and_Getters, Coordinates)
{
    ASSERT_EQ(C.GetId(), 1);
    ASSERT_EQ(C.GetCurCell(), W.GetField()[7][7]);
    ASSERT_EQ(C.GetBuildingType(), 'a');
}

TEST (Building_Methods, TakeDamage_Heal_Destroy)
{
    int hp = C.GetHp();
    C.TakeDamage(100);
    C.Heal();
    ASSERT_EQ(C.GetHp(), hp);
    C.Destroy(W);
    ASSERT_EQ(W.GetBuildings().size(), 3);
}

Castle C1(W, 7, 7);

TEST (Castle_Method, LevelUp)
{
    int x = C1.GetHp();
    ASSERT_EQ(C1.LevelUp(), 0);
    ASSERT_EQ(C1.LevelUp(), 0);
    ASSERT_EQ(C1.LevelUp(), 0);
    ASSERT_EQ(C1.LevelUp(), 0);
    ASSERT_EQ(C1.LevelUp(), 1);
    ASSERT_NE(C1.GetHp(), x);
}

/// Class Tower

Tower T(W, 5, 5);

TEST (Tower_Constructor_and_Getters, Coordinates)
{
    ASSERT_EQ(T.GetCurCell(), W.GetField()[5][5]);
    ASSERT_EQ(T.GetDamage(), 30);
    ASSERT_EQ(T.GetRadius(), 3);
    ASSERT_EQ(T.GetHp(), 100);
    ASSERT_EQ(T.GetId(), 3);
    Knight K1(W, 4, 4);
    T.FindTargets(W);
}

TEST (Tower_Method, LevelUp)
{
    T.LevelUp();
    ASSERT_NE(T.GetHp(), 100);
}

TEST (Tower_Method, DealDamage)
{
    Knight K2(W, 4, 5);
    T.FindTargets(W);
    int hp = K2.GetHp();
    T.DealDamage();
    ASSERT_NE(K2.GetHp(), hp);
}

/// Class Wall

TEST (Wall_Constructor, Coordinates)
{
    Wall VV(W, 3, 3);
    ASSERT_EQ(VV.GetHp(), 200);
    ASSERT_EQ(VV.GetCurCell(), W.GetField()[3][3]);
    ASSERT_EQ(VV.GetCurCell()->GetLock(), true);
}

TEST (Wall_Method, LevelUp)
{
    Wall VV(W, 3, 3);
    VV.LevelUp();
    ASSERT_NE(VV.GetHp(), 200);
}

/// Class Spawner

TEST (Spawner_Constructor_and_Getters, Coordinates)
{
    Spawner S(W, 8, 8);
    ASSERT_EQ(S.GetHp(), 100);
    ASSERT_EQ(S.GetBuildingType(), 'd');
    ASSERT_EQ(S.GetCurCell()->GetLock(), true);
    ASSERT_EQ(S.GetCurCell(), W.GetField()[8][8]);
}

TEST (Spawner_Method, LevelUp)
{
    Spawner S(W, 8, 8);
    int hp = S.GetHp();
    S.LevelUp();
    ASSERT_EQ(S.GetHp(), hp);
}

/// Class Knight and Warrior

Knight Kn (W, 4, 1);

TEST (Knight_Constructor_and_Getters, Coordinates)
{
    ASSERT_EQ(Kn.GetHp(), 100);
    ASSERT_EQ(Kn.GetCurCell(), W.GetField()[1][4]);
    ASSERT_EQ(Kn.GetDamage(), 10);
    ASSERT_EQ(Kn.GetX(), 4 * 176);
    ASSERT_EQ(Kn.GetY(), 1 * 44);
}

TEST (Warrior_Method, Move)
{
    W.GetField()[1][4]->A_star(W, *W.GetField()[1][6]);
    Kn.Move();
    ASSERT_EQ(Kn.GetCurCell(), W.GetField()[1][5]);
}

TEST (Warrior_Methods, AddtoX_AddtoY)
{
    Kn.AddtoX(1);
    Kn.AddtoY(1);
    ASSERT_EQ(Kn.GetX(), 704 + 1);
    ASSERT_EQ(Kn.GetY(), 1 * 44 + 1);
}

TEST (Warrior_Method, DealDamage)
{
    Kn.DealDamage(C);
    ASSERT_NE(1000, C.GetHp());
}

TEST (Warrior_Method, TakeDamage)
{
    int hp = Kn.GetHp();
    Kn.TakeDamage(30);
    ASSERT_NE(Kn.GetHp(), hp);
}

TEST (Warrior_Method, DirectionOfNextCell)
{
    ASSERT_EQ(Kn.DirectionOfNextCell().second, 0);
    ASSERT_EQ(Kn.DirectionOfNextCell().first, 1);
}

TEST (Warrior_Method, LevelUp)
{
    int hp = Kn.GetHp();
    Kn.LevelUp();
    ASSERT_NE(Kn.GetHp(), hp);
    ASSERT_EQ(Kn.LevelUp(), 0);
    ASSERT_EQ(Kn.LevelUp(), 0);
    ASSERT_EQ(Kn.LevelUp(), 0);
    ASSERT_EQ(Kn.LevelUp(), 1);
}

/// Class Juggernaut

Juggernaut Jug (W, 6, 3);

TEST (Juggernaut_Constructor, Coordinates)
{
    ASSERT_EQ(Jug.GetHp(), 100);
    ASSERT_EQ(Jug.GetCurCell(), W.GetField()[3][6]);
    ASSERT_EQ(Jug.GetDamage(), 10);
    ASSERT_EQ(Jug.GetX(), 6 * 176);
    ASSERT_EQ(Jug.GetY(), 3 * 44);
}

/// Class Aviation

Aviation Av (W, 1, 8);

TEST (Aviation_Constructor, Coordinates)
{
    ASSERT_EQ(Av.GetHp(), 100);
    ASSERT_EQ(Av.GetCurCell(), W.GetField()[8][1]);
    ASSERT_EQ(Av.GetDamage(), 10);
    ASSERT_EQ(Av.GetX(), 1 * 176 + 88);
    ASSERT_EQ(Av.GetY(), 8 * 44);
}

/// Class Hero

Hero H (W, 2, 1);

TEST (Hero_Constructor, Coordinates)
{
    ASSERT_EQ(H.GetHp(), 100);
    ASSERT_EQ(H.GetCurCell(), W.GetField()[1][2]);
    ASSERT_EQ(H.GetDamage(), 10);
    ASSERT_EQ(H.GetX(), 2 * 176);
    ASSERT_EQ(H.GetY(), 1 * 44);
}