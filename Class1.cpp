//  Class1.cpp
//  Helper Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//  

#include "Class1.h"
#include <iostream>
using namespace std;

int Class1::getHighestHealth(int partyHealths[])
{
    int highestSlot = 1;
    int highestHealth = partyHealths[1];
    for(int i = 2; i < PARTY_SIZE; i++)
    {
        if(highestHealth < partyHealths[i])
        {
            highestHealth = partyHealths[i];
            highestSlot = i;
        }
    }
    return highestSlot;
}

string Class1::swapToHighestHealth(int partyHealths[], int activeSlot)
{
    int swapSlot = getHighestHealth(partyHealths);
    string response;

    //if swapping with other than itself
    if(swapSlot != activeSlot)
    {
        switch(swapSlot)
        {
            case 1:
                response = "s1";
                break;
            case 2:
                response = "s2";
                break;
            case 3:
                response = "s3";
                break;
            case 4:
                response = "s4";
                break;
        }
    }
    //otherwise
    else
    {
        response = "a";
    }
    return response;
}

bool Class1::isGonnaDie(int health, int enemyATK)
{
    if (health <= enemyATK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Class1::areOthersGonnaDie(int partyHealths[], int partyDamages[])
{
    for(int i = 1; i < PARTY_SIZE; i++)
    {
        //hypothesizing future health one turn later
        int remainHealth = partyHealths[i] - partyDamages[i];
        if(!isGonnaDie(remainHealth, partyDamages[i]))
        {
            return false;
        }
    }
    return true;
}

