#include "Minesweeper.h"

#include <iostream>

int main (int argc, char *argv[]){
  int dim;
  std::cout << "Zadej velikost hracího pole: \n";
  std::cin >> dim;
  MineSweeper m(dim);
  std::cout << m.Display();
  while (true) {
    std::cout << "Zadej souřadnice: (x, y) -> \n";
    int i, j;
    std::cin >> i >> j;
    Reply reply = m.Move(i, j);
    if (reply == ILLEGAL) {
      std::cout << "Neplatná souřadnice!\n";
      continue;
    }
    std::cout << m.Display();
    if (reply == MINE) {
      std::cout << "Prohrál jsi!\n";
      break;
    }
    if (reply == USER_WON) {
      std::cout << "Výhra!\n";
      break;
    }
  }
}

