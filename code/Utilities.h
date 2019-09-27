#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
__declspec(selectany) int ICONSIZE = 50;
__declspec(selectany) int NOS; // number of Static Objects
__declspec(selectany) int MOVEG = 1; // Move Guards = true
__declspec(selectany) int WAITB = 1; // Wait 5 seconds to load another bomb
__declspec(selectany) int NUMOFBOMBS = 5; // Wait 5 seconds to load another bomb
__declspec(selectany) bool DONOTENTER = true; // if some explosion happens and a guard was harmed so change to false
__declspec(selectany) bool RESTART = false; // Restart Level
__declspec(selectany) bool NEWLEVEL = false; // NEWLEVEL Level
__declspec(selectany) int ROWS = 0; // fixed from unsigned to int
__declspec(selectany) int COLS = 0; // fixed from unsigned to int
__declspec(selectany) int BOMB_LIM;
__declspec(selectany) int TIME_LIM;
__declspec(selectany) unsigned LEVEL = 0;
__declspec(selectany) bool RESTART_OBJ = false;

 /// idea
__declspec(selectany) int NUMOFGUARDS = 0; // Update infoBar
__declspec(selectany) int LIFE = 0; // Life increase or decrease 0 = false 1 = increase -1 = decrease
__declspec(selectany) int SCORE = 0; // score
__declspec(selectany) bool T = true; // life != 0 && level != 5
#endif