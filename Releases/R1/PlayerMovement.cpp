#include "PlayerMovement.hpp"
#include <iostream>
#include <string>

using namespace mysqlpp;
using namespace std;

void PrintInstrucitons(Player& UserPlayer)
{
    /*
    A funciton that gives the user instrucitons about what the user can do.
    */
    
    cout << "Your health is " << UserPlayer.getHealth() << endl;
    cout << "Number of enemies remaining: " << Enemies.size() << endl;
    
    //Print the enemies health stats to the screen
    PrintEnemiesStats();
    
    cout << "To move up or attack the player above you, enter w" << endl;
    cout << "To move down or attack the player below you, enter s" << endl;
    cout << "To move left or attack the player to your left, enter a" << endl;
    cout << "To move rght or attack the player to your right, enter d" << endl;
}

void PrintEnemiesStats()
{
    /*
    A funciton that prints out the enemies health
    */
    for (Enemy EachEnemy : Enemies)
    {
        cout << "EnemyID " << EachEnemy.getEntityID() << " health is " << EachEnemy.getHealth() << endl;
    }
}

string WhereToMove()
{
    /*
    A function that asks the user to pick a direction to move or attack in and only accpets the input once a valid input has been entered.
    */
    bool CommandAccepted = false;
    
    string EnteredCommand;
    while (CommandAccepted == false)
    {
        cout << "Please enter a command from the list above:";
        cin >> EnteredCommand;

        if (EnteredCommand == "w" || EnteredCommand == "s" || EnteredCommand == "a" || EnteredCommand == "d")
        {
            CommandAccepted = true;
        }
        else
        {
            cout << "Incorrect Command. Please try again." << endl;
        }
    }
    
   return EnteredCommand;
}

bool CanPlayerMove(string AcceptedCommand, Player& UserPlayer)
{
    /*
    A function that checks that the array value for the direction that the user
    has entered is empty and returns true if the user can move in that direction.
    If not it returns false.
    */
    if (AcceptedCommand == "w")
    {
        //check to see if there is space above the user. If so return true
        if (arrCurrentMap[UserPlayer.getXPos()][UserPlayer.getYPos()-1] == ' ')
        {
            return true;
        }
    }
    else if (AcceptedCommand == "s")
    {
        //check to see if there is space below the user. If so return true
        if (arrCurrentMap[UserPlayer.getXPos()][UserPlayer.getYPos()+1] == ' ')
        {
            return true;
        }
    }
    else if (AcceptedCommand == "a")
    {
        //check to see if there is space to the left the user. If so return true
        if (arrCurrentMap[UserPlayer.getXPos()-1][UserPlayer.getYPos()] == ' ')
        {
            return true;
        }
    }
    else if (AcceptedCommand == "d")
    {
        //check to see if there is space to the right the user. If so return true
        if (arrCurrentMap[UserPlayer.getXPos()+1][UserPlayer.getYPos()] == ' ')
        {
            return true;
        }
    }
    else
    { 
        //In any other cases, apart from the ones above return false
        return false;
    }
    
}

bool CanPlayerAttack(string AcceptedCommand, Player& UserPlayer)
{
    /*
    A function that checks that the array value for the direction that the user
    has entered has an enemy and if so it returns true. If not it returns false.
    This will indicate thay the user can attack the appropriate enemy.
    */
    if (AcceptedCommand == "w")
    {
        //check to see if there is an enemy above the user. If so return true
        if (arrCurrentMap[UserPlayer.getXPos()][UserPlayer.getYPos()-1] == 'e')
        {
            return true;
        }
    }
    else if (AcceptedCommand == "s")
    {
        //check to see if there is an enemy below the user. If so return true
        if (arrCurrentMap[UserPlayer.getXPos()][UserPlayer.getYPos()+1] == 'e')
        {
            return true;
        }
    }
    else if (AcceptedCommand == "a")
    {
        //check to see if there is an enemy to the left of the user. If so return true
        if (arrCurrentMap[UserPlayer.getXPos()-1][UserPlayer.getYPos()] == 'e')
        {
            return true;
        }
    }
    else if (AcceptedCommand == "d")
    {
        //check to see if there is an enemy to the right of the user. If so return true
        if (arrCurrentMap[UserPlayer.getXPos()+1][UserPlayer.getYPos()] == 'e')
        {
            return true;
        }
    }
    
    return false;
}

int PlayerProcedures()
{
    /*
    A funtions that prints the instructions to the screen and processes the 
    given commnads by calling different procedures/funcitons.
    */
    
    //Call PrintInstrucitons
    PrintInstrucitons(PlayerInstance);
    
    //while player cannot move
    bool PlayerCanMove = false;
    while (PlayerCanMove == false)
    {
         //ask the user where they want to move to
         string EnteredDirection = WhereToMove();
        
         //Check if the user can move in the entered direciton
         PlayerCanMove = CanPlayerMove(EnteredDirection, PlayerInstance);
        
        //If the user can move, then move the user, other wise ckeck if the player can attack
         if (PlayerCanMove == false)
         {
             bool PlayerAttack = CanPlayerAttack(EnteredDirection, PlayerInstance);
             
             if (PlayerAttack == true)
             {
                 AttackEnemy(EnteredDirection);
                 PlayerCanMove = true;
             }
             else
             {                 
                 //call PrintMap
                 PrintMap();
                 
                 //Tell the user that they couldn,t move or attack
                 cout << "Player can't move or attack in that direciton. Please try another direction." << endl;
                 
                 //Call PrintInstrucitons
                 PrintInstrucitons(PlayerInstance);
             }
            
         }
         else
         {
            //Call MovePlayer
            MovePlayer(EnteredDirection, PlayerInstance);
         }
    }  
}

void MovePlayer(string Direction, Player& UserPlayer)
{
    /*
    A funciton that updates the array to move the player by the direciton that was given in the funtion call.
    */
    
    arrCurrentMap[UserPlayer.getXPos()][UserPlayer.getYPos()] = ' ';
    UserPlayer.move(Direction);
    arrCurrentMap[UserPlayer.getXPos()][UserPlayer.getYPos()] = 'p';
}

void PlayerAttackEnemy(Player& UserPlayer, Enemy& EnemyToAttack, int offset)
{
    /*
    A function which attack the enemy given and removes the enemy from the enemies vector
    */
    
    UserPlayer.attack(EnemyToAttack);
    Enemies[offset].setHealth(EnemyToAttack.getHealth());
    if (EnemyToAttack.getHealth() <= 0)
    {
        arrCurrentMap[EnemyToAttack.getXPos()][EnemyToAttack.getYPos()] = ' ';
        Enemies.erase(Enemies.begin()+offset);
    }
}

void AttackEnemy(string Direction)
{
    /*
    A function that takes the direction as input and attacks the enemy in the appropriate direction.
    The actual attack procedure is in the Entity class which the enemy class inherits.
    */
    
    int PositionInEnemiesVec = 0;
    for (Enemy EachEnemy : Enemies)
    {
        if (Direction == "w")
        {
            if (EachEnemy.getYPos() == PlayerInstance.getYPos()-1 && EachEnemy.getXPos() == PlayerInstance.getXPos())
            {
                PlayerAttackEnemy(PlayerInstance, EachEnemy, PositionInEnemiesVec);
                break;
            }
        }
        
        else if (Direction == "s")
        {
            if (EachEnemy.getYPos() == PlayerInstance.getYPos()+1 || EachEnemy.getXPos() == PlayerInstance.getXPos())
            {
                PlayerAttackEnemy(PlayerInstance, EachEnemy, PositionInEnemiesVec);
                break;
            }
        }
        
        else if (Direction == "a")
        {
            if (EachEnemy.getXPos() == PlayerInstance.getXPos()-1 && EachEnemy.getYPos() == PlayerInstance.getYPos())
            {
                PlayerAttackEnemy(PlayerInstance, EachEnemy, PositionInEnemiesVec);
                break;
            }
            break;
        }
        
        else if (Direction == "d")
        {
            if (EachEnemy.getXPos() == PlayerInstance.getXPos()+1 && EachEnemy.getYPos() == PlayerInstance.getYPos())
            {
                PlayerAttackEnemy(PlayerInstance, EachEnemy, PositionInEnemiesVec);  
                break;
            }
        }
        PositionInEnemiesVec += 1;
    }
}
