int safe_row(int r ) {
    if (r > rows - 1) return r - rows;
    if (r < 0) return r + rows;
    return r;
}
int safe_col(int c ) {
    if (c > cols - 1) return c - cols;
    if (c < 0) return c + cols;
    return c;
}
int situation(int stage[rows][cols], int row,int col) {
    int sum = 0;
    sum += stage[safe_row(row - 1)][col];
    sum += states*stage[row][safe_col(col + 1)];
    sum += states*states*stage[safe_row(row + 1)][col];
    sum += states*states*states*stage[row][safe_col(col - 1)];
    sum += states*states*states*states*stage[row][col];
    return sum;
}
void flip(int stage[rows][cols], int r,int c) {
    stage[r][c] = !stage[r][c];
}
void advance(int stage[rows][cols], int r,int c) {
    stage[r][c] += 1;
    if (stage[r][c] > states) stage[r][c] = 0;
}

void update_player(player* p , int stage[rows][cols]) {
    int temp[memory];
    int old_row = p->row[0];
    int old_col = p->col[0];
    int s = situation(stage, p->row[0], p->col[0]);
    int r = p->response[s];
    stage[p->row[0]][p->col[0]] = p->trace;
    switch (r) {
        case 0 : p->row[0] = safe_row(p->row[0] - 1);break;
        case 1 : p->row[0] = safe_row(p->row[0] - 1);p->col[0] = safe_col(p->col[0] + 1);break;
        case 2 : p->col[0] = safe_col(p->col[0] + 1);break;
        case 3 : p->row[0] = safe_row(p->row[0] + 1);p->col[0] = safe_col(p->col[0] + 1);break;
        case 4 : p->row[0] = safe_row(p->row[0] + 1);break;
        case 5 : p->row[0] = safe_row(p->row[0] + 1);p->col[0] = safe_col(p->col[0] - 1);break;
        case 6 : p->col[0] = safe_col(p->col[0] - 1);break;
        case 7 : p->row[0] = safe_row(p->row[0] - 1);p->col[0] = safe_col(p->col[0] - 1);break;
    }
    for (int i = memory - 2; i > 0 ; i-- ) {
        p->row[i+1] = p->row[i];
    }
    p->row[1] = old_row;
    for (int i = memory - 2; i > 0 ; i-- ) {
        p->col[i+1] = p->col[i];
    }
    p->col[1] = old_col;
    //now a random mutation, which turns out to really matter
    p->response[arc4random_uniform(situations)] = arc4random_uniform(responses);

}
void update_cast(player cast[players], int stage[rows][cols]) {
    for (int p = 0; p < players; p++) update_player(&cast[p], stage);
}
void mark_positions(player cast[players], int taken[rows][cols]) {
    for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) taken[i][j] = 0;
    for (int p = 0; p < players; p++) taken[cast[p].row[0]][cast[p].col[0]] = 1;
}