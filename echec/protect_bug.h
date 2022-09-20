int protect_bug (){
  char size_board[12] = {0};
  int unit = 0;
  int result;
  while (unit == 0) {
    scanf("%11s", size_board);
    for (int i = 0 ; i < 9 ; i++){
      if ( (size_board[i] < 58) && (size_board[i] > 48) ){
        unit = 1;
        break;
      }
    }
  }
  sscanf(size_board, "%2d", &result);
  if (result < 0){
    result = result - 2 * result;
  }
  return result;
}