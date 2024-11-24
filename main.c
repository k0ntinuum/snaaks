int main() {
    bool f = true; 
    hide_cursor();
    cls();
    int stage[rows][cols];
    int taken[rows][cols];
    randomize_stage(stage);
    player cast[players];
    randomize_cast(cast);
    for (int i = 0 ; i < 10000000; i++) {
        update_cast(cast,stage);
        cls();
        print_avatars(cast);
        printf("\n");
        usleep(32000);
    }
    show_cursor();
    cursor_to(rows+5,0);
}