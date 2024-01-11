#pragma once

#include <array>

/*!
 * Providing space for cell rearrangement  
 */
class Board {
 public:
  /*!
   * Generation of random cells with a specific filling   
   */
  Board();
  //~Board();
  /*!
   * Displaying the current location of cells   
   */
  void Show();
  /*!
   * Safe method of obtaining X coordinates 
   */
  int GetX(int x);
  /*!
   * Safe method of obtaining Y coordinates 
   */
  int GetY(int y);
  /*!
   * Create the next generation of cells 
   */
  void NextGen();
  /*!
   * Writing the current field state to a file
   */
  void WriteToFile(int iter_numb);
  /*!
   * Reading field state from file
   */
  void ReadFromFile();

 private:
  static const int width = 20;
  static const int height = 20;
  static const int fill = 10;
  std::array<std::array<int, height>, width> curr_field;
  std::array<std::array<int, height>, width> prev_field;
};