#include "colors.h" // If you want to make your map look pretty and use colors :)
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono> // timer
#include <ctime>
#include <cstdlib>
#include <thread> // run to different things at the same time

using namespace std;

char character = '&';
char attackChar = '*';
char enemyChar = '!'; // change later to ඞ
vector<int> characterPosition = {25, 25};
vector<int> characterLastPosition = {25, 25};
vector<int> enemyPosition = {25, 2};
vector<int> enemyLastPosition = {25, 2};
bool touching = false;
int chickens = 0;
int lvl = 0;
// Map declaration

vector<string> world = {
    // width 124 height 30
    "****************************************************************************************************************************", // y = 0
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "*                                                                                                                          *",
    "****************************************************************************************************************************",
    "*                                                                                                                          *",
    "*   Chicken count: ",to_string(chickens), "                                                                                                       *",
    "*                                                                                                                          *",
    "****************************************************************************************************************************",

}; // y = 30
// x == 1                                                                                                                    x = 124

void printMap()
{
  string map;
  for (int i = 0; i < world.size(); i++)
  {

    if(i == 33 || i == 32){
    map = map + world.at(i);
    }
    else {
    map = map + world.at(i) +  "\n";

    }
  }
  cout << map << endl;
};
void updatePosition(vector<int> &position)
{ // position [x , y]
  bool ret = true;
  if (characterPosition[0] >= 123)
  {
    characterPosition[0]--;
    ret = false;
  }
  if (characterPosition[0] <= 0)
  {
    characterPosition[0]++;
    ret = false;
  }
  if (characterPosition[1] >= 30)
  {
    characterPosition[1]--;
    ret = false;
  }
  if (characterPosition[1] <= 0)
  {
    characterPosition[1]++;
    ret = false;
  }
  if (ret)
  {
    for (int i = 0; i < world.size(); i++)
    {
      for (int j = 0; j < world.at(i).size(); j++) // delete last position
      {
        if (characterLastPosition[0] == j && characterLastPosition[1] == i)
        {
          world.at(i).at(j) = ' ';
        }
      }
    }
    // save last position
    characterLastPosition[0] = position[0];
    characterLastPosition[1] = position[1];

    for (int i = 0; i < world.size(); i++) // add new position
    {
      for (int j = 0; j < world.at(i).size(); j++)
      {
        if (position[0] == j && position[1] == i)
        {
          world.at(i).at(j) = character; // y value goes first then the x value
        }
      }
    }
  }
  printMap();
};
void enemyChangePosition()
{

  srand(time(0));
  int random = rand() % 4;
  if (random == 0)
  {
    enemyPosition[0]--;
  }
  else if (random == 1)
  {
    enemyPosition[0]++;
  }
  else if (random == 2)
  {
    enemyPosition[1]--;
  }
  else if (random == 3)
  {
    enemyPosition[1]++;
  }

  bool ret = true;
  if (enemyPosition[0] >= 124)
  {
    enemyPosition[0]--;
    ret = false;
  }
  if (enemyPosition[0] <= 0)
  {
    enemyPosition[0]++;
    ret = false;
  }
  if (enemyPosition[1] >= 30)
  {
    enemyPosition[1]--;
    ret = false;
  }
  if (enemyPosition[1] <= 0)
  {
    enemyPosition[1]++;
    ret = false;
  }
  if (ret)
  {
    for (int i = 0; i < world.size(); i++)
    {
      for (int j = 0; j < world.at(i).size(); j++) // delete last position
      {
        if (enemyLastPosition[0] == j && enemyLastPosition[1] == i)
        {
          world.at(i).at(j) = ' ';
        }
      }
    }
    // save last position
    enemyLastPosition[0] = enemyPosition[0];
    enemyLastPosition[1] = enemyPosition[1];

    for (int i = 0; i < world.size(); i++) // add new position
    {
      for (int j = 0; j < world.at(i).size(); j++)
      {
        if (enemyPosition[0] == j && enemyPosition[1] == i)
        {
          world.at(i).at(j) = enemyChar; // y value goes first then the x value
        }
      }
    }
  }
  printMap();
}
void enemyMovement()
{
  while (true)
  {
    enemyChangePosition();
    this_thread::sleep_for(chrono::milliseconds(lvl));
    if(touching){
      chickens = chickens + 1;
      world[33] = to_string(chickens);
      touching = false;
        // thread enemyM2(enemyMovement);
        // thread check2(checking);
    return;
  }

  }
}
void checking(){
  while (true)
  {
    if(enemyPosition[0] == characterPosition[0] && enemyPosition[1] == characterPosition[1]){
    touching = true;
    return;
    }
  }
  
}

int main()
{
  // vector <vector<map>> char; // You can use a 2D vector if you'd like, but it's a lot better to emulate a 2D vector with a 1D one.
  cout << "Select your level (Easy: 1, Normal: 2, Hard: 3)" << endl;
  cin >> lvl;
  if(lvl == 1){
    lvl = 1000;

  }
  else if(lvl == 2){
    lvl = 200;

  }else {
    lvl = 150;
  }

  printMap();
  updatePosition(characterPosition);
  // printMap();
  // updatePosition(characterPosition);
  // printMap();

  // thread enemyM(enemyMovement);
  thread enemyM(enemyMovement);
  thread check(checking);
  while (true)
  {

    // cin.ignore();
    // this_thread::sleep_for(chrono::milliseconds(166));
    // cin.ignore();
    set_raw_mode(true);
    int input = quick_read();
    if (input == 'q')
      return 0;
    if (input == 'w')
    {
      characterPosition[1]--;
      updatePosition(characterPosition);
    }
    if (input == 's')
    {
      characterPosition[1]++;
      updatePosition(characterPosition);
    }
    if (input == 'a')
    {
      characterPosition[0]--;
      updatePosition(characterPosition);
    }
    if (input == 'd')
    {
      characterPosition[0]++;
      updatePosition(characterPosition);
    }
    // cout << characterPosition[0] << "-" << characterPosition[1] << endl;

  }
  // Wait for both threads to finish
  enemyM.join();


}

// Collect chickens, your name is Randle