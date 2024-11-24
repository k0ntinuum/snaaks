void randomize_stage(int stage[rows][cols]) {
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++)
            stage[i][j] = arc4random_uniform(states);
}
void randomize_cast(player cast[players]) {
    int h = 255;
    for (int p = 0; p < players; p++) {
        if ((p % 2) == 0 ) cast[p].avatar = 'O';
        if ((p % 2) == 1 ) cast[p].avatar = '|';
        //if (p == 2) cast[p].avatar = '@';
        cast[p].trace = arc4random_uniform(states);
        for (int s = 0; s < situations; s++) cast[p].response[s] = arc4random_uniform(responses);
        cast[p].row[0] = arc4random_uniform(rows);
        for (int i = 1; i < memory; i++ ) cast[p].row[i] = cast[p].row[0];
        cast[p].col[0] = arc4random_uniform(cols);
        for (int i = 1; i < memory; i++ ) cast[p].col[i] = cast[p].col[0];
    }      
}
