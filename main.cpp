//  CS1337_Project2_Josiah_Rise
//
//  Created by Josiah Rise on 2/17/17.
//  jdr160730
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream loadMap;

int sizeMap (int &rowLength) {
   char read;
   string readS;
   int rows = 1;
   int count = 0;
   
   loadMap.open("map.txt");
   
   while (read != '\n') {
      loadMap.seekg(count, ios::beg);
      loadMap.get(read);
      count++;
   }
   cout << "row length: " << count << endl;
   rowLength = count;
   
   while (getline(loadMap, readS)) {
      rows++;
   }
   cout << "Rows: " << rows << endl;
   
   loadMap.close();
   return (rows * rowLength);
}

void fillMap (char *ptr, int mapLength) {
   loadMap.open("map.txt");
   for (int i = 0;i < mapLength; i++) {
      loadMap.get(*ptr);
      ptr++;
   }
   loadMap.close();
}

bool findPlayerStart(char *&playerPos, int mapLength) {
   char read;
   for (int i = 0; i < mapLength; i++) {
      playerPos++; //The first char in the file should always be part of the border
      if (*playerPos == '&') {
         return true;
      }
   }
   return false;
}

void printMap (char *ptr, int mapLength) {
   for (int i = 0;i < mapLength; i++) {
      cout << *ptr;
      ptr++;
   }
}

bool north (char *&playerPos, int rowLength) {
   char *check;
   check = playerPos;
   check -= rowLength;
   if (*check == ' ') {
      *playerPos = ' ';
      playerPos = check;
      *playerPos = '&';
      return true;
   } else {
      return false;
   }
}

bool east (char *&playerPos, int rowLength) {
   char *check;
   check = playerPos;
   check++;
   if (*check == ' ') {
      *playerPos = ' ';
      playerPos = check;
      *playerPos = '&';
      return true;
   } else {
      return false;
   }
}

bool south (char *&playerPos, int rowLength) {
   char *check;
   check = playerPos;
   check += rowLength;
   if (*check == ' ') {
      *playerPos = ' ';
      playerPos = check;
      *playerPos = '&';
      return true;
   } else {
      return false;
   }
}

bool west (char *&playerPos, int rowLength) {
   char *check;
   check = playerPos;
   check--;
   if (*check == ' ') {
      *playerPos = ' ';
      playerPos = check;
      *playerPos = '&';
      return true;
   } else {
      return false;
   }
}

void help () {
   
}

void save () {
   
}

int main () {
   char input;
   bool playerFound;
   bool quit = false;
   int rowLength;
   int mapLength = sizeMap(rowLength);
   char map[mapLength];
   char *mapPtr;
   mapPtr = map;
   char *playerPos;
   
   fillMap(mapPtr, mapLength);
   playerPos = map;
   findPlayerStart(playerPos, mapLength);
   
   cout << "You find yourself in a small village..." << endl;
   printMap(mapPtr, mapLength);
   cout << "Enter an action (h for commands)" << endl;
   while (!quit) {
      cin >> input;
      if (input == 'h') {
         
      } else if (input == 'n') {
         if (!north(playerPos, rowLength)) {
            cout << "Nope" << endl;
            continue;
         }
      } else if (input == 'e') {
         if (!east(playerPos, rowLength)) {
            cout << "Nope" << endl;
            continue;
         }
      } else if (input == 's') {
         if (!south(playerPos, rowLength)) {
            cout << "Nope" << endl;
            continue;
         }
      } else if (input == 'w') {
         if (!west(playerPos, rowLength)) {
            cout << "Nope" << endl;
            continue;
         }
      } else if (input == 'q') {
         quit = true;
      }
      printMap(mapPtr, mapLength);
   }
   
   return 0;
}
