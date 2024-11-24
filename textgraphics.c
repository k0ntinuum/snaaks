void rgb(int r, int g, int b) {
    printf("\x1b[38;2;%d;%d;%dm",r,g,b);
}
void cursor_to(int r, int c) {
    printf("\x1b[%d;%dH",r,c);
}
void cls() {
    printf("\x1b[2J");
}
void reverse_text(void) {
    printf("\x1b[7m");
}
void stop_reverse_text(void) {
    printf("\x1b[27m");
}
void hide_cursor(void) {
    printf("\x1b[?25l");
}
void show_cursor(void) {
    printf("\x1b[?25h");
}