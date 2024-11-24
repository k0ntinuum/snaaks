void print_cell(int i) {
    switch(i) {
        case 0: printf(" ");break;
        case 1: printf("\u2588");break;
        case 2: printf("\u2591");break;
    }
}

void print_avatar(player* p) {
    int h; 
    for (int i = memory - 1; i >= 0 ; i-- ) {
        cursor_to(stage_down_start + p->row[i], stage_left_start + p->col[i]);
        rgb(255,255,255);
        if (i == 0) printf("%c", p->avatar); else printf("\u2588");
    }
}
void print_avatars(player cast[players]) {
    for (int p = 0; p < players; p++) print_avatar(&cast[p]);
}