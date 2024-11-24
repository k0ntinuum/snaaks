const int rows = 10;
const int cols = 20;
const int players = 9;
const int memory = 5;
const int situations = 32;
const int responses = 8;
const int states = 2;
const int stage_down_start = 2;
const int stage_left_start = 5;

typedef struct {
    char avatar;
    int trace;
    int response[situations];
    int row[memory];
    int col[memory];
} player;

